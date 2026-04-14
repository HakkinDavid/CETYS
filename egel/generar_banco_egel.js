#!/usr/bin/env node

const fs = require("fs");
const path = require("path");

const INPUT_FILES = [
    "casos.txt",
    "lengua.txt",
    "conceptos.txt",
];

const OUTPUT_FILE = "banco_preguntas.js";
const AREA_FALLBACK = ["Aplicación", "Base", "Algoritmia", "IA"];

const AREA_RULES = [
    {
        area: "IA",
        patterns: [
            /\bia\b/i,
            /\binteligencia artificial\b/i,
            /\baprendizaje\b/i,
            /\bmachine learning\b/i,
            /\bred neuronal\b/i,
            /\bregresi(?:o|ó)n\b/i,
            /\bclasific(?:a|á)ci(?:o|ó)n\b/i,
            /\bclustering\b/i,
            /\bk-means\b/i,
            /\bsvm\b/i,
            /\bnaive bayes\b/i,
            /\bpca\b/i,
            /\bembedding\b/i,
            /\bword2vec\b/i,
            /\blenguaje natural\b/i,
        ],
    },
    {
        area: "Algoritmia",
        patterns: [
            /\balgoritm/i,
            /\bgrafo/i,
            /\b(?:b[úu]squeda|search)\b/i,
            /\bordenamiento\b/i,
            /\bsort\b/i,
            /\bcomplejidad\b/i,
            /\brecurs/i,
            /\b(?:dijkstra|kruskal|prim|bellman-ford|floyd)\b/i,
            /\b(?:dfs|bfs)\b/i,
            /\bheap\b/i,
            /\bpila\b/i,
            /\bcola\b/i,
            /\b(?:lista enlazada|linked list)\b/i,
            /\b(?:árbol|arbol)\b/i,
            /\bmatriz\b/i,
            /\bbacktracking\b/i,
        ],
    },
    {
        area: "Base",
        patterns: [
            /\bbase de datos\b/i,
            /\bdbms\b/i,
            /\btransacci(?:o|ó)n\b/i,
            /\bacid\b/i,
            /\bnormaliz/i,
            /\b(?:tcp|udp|ip|dns|nat|vlan|arp|icmp|vpn|http)\b/i,
            /\bred(?:es)?\b/i,
            /\brouter\b/i,
            /\bsistema operativo\b/i,
            /\bmemoria\b/i,
            /\bdeadlock\b/i,
            /\bplanificaci(?:o|ó)n\b/i,
            /\bsistema de archivos\b/i,
            /\braid\b/i,
            /\bconsenso\b/i,
            /\bconcurrencia\b/i,
        ],
    },
];

function normalizeWhitespace(text) {
    return text.replace(/\s+/g, " ").trim();
}

function splitBlocks(content) {
    const lines = content.replace(/\r\n?/g, "\n").split("\n");
    const blocks = [];
    let current = [];

    for (const line of lines) {
        if (/^(?:Numero|Número) de pregunta:\s*\d+/i.test(line)) {
            if (current.length > 0) {
                blocks.push(current);
            }
            current = [line];
            continue;
        }

        if (current.length > 0) {
            current.push(line);
        }
    }

    if (current.length > 0) {
        blocks.push(current);
    }

    return blocks;
}

function parseBlock(lines) {
    const questionNumberMatch = lines[0].match(/(\d+)/);
    const parsed = {
        number: questionNumberMatch ? Number(questionNumberMatch[1]) : null,
        questionLines: [],
        options: [],
        answerLetter: null,
    };

    let currentSection = null;
    let currentOption = null;

    for (const rawLine of lines.slice(1)) {
        const line = rawLine.trim();

        if (!line || /^=+$/.test(line) || /^[-*_]{3,}$/.test(line)) {
            continue;
        }

        const answerMatch = line.match(/^Respuesta correcta:\s*([A-Z])/i);
        if (answerMatch) {
            parsed.answerLetter = answerMatch[1].toUpperCase();
            currentSection = "answer";
            currentOption = null;
            continue;
        }

        const questionMatch = line.match(/^Pregunta:\s*(.*)$/i);
        if (questionMatch) {
            parsed.questionLines.push(questionMatch[1]);
            currentSection = "question";
            currentOption = null;
            continue;
        }

        const optionMatch = line.match(/^(?:Inciso\s+)?([A-Z])[):]\s*(.*)$/i);
        if (optionMatch) {
            currentOption = {
                label: optionMatch[1].toUpperCase(),
                text: optionMatch[2].trim(),
            };
            parsed.options.push(currentOption);
            currentSection = "option";
            continue;
        }

        if (currentSection === "question") {
            parsed.questionLines.push(line);
            continue;
        }

        if (currentSection === "option" && currentOption) {
            currentOption.text = `${currentOption.text} ${line}`.trim();
        }
    }

    const question = normalizeWhitespace(parsed.questionLines.join(" "));
    const options = parsed.options.map((option) => normalizeWhitespace(option.text));
    const answer = parsed.options.findIndex((option) => option.label === parsed.answerLetter);

    if (!question || options.length < 2 || answer < 0) {
        return null;
    }

    return {
        question,
        options,
        answer,
    };
}

function inferArea(text, fallbackIndex) {
    for (const rule of AREA_RULES) {
        if (rule.patterns.some((pattern) => pattern.test(text))) {
            return rule.area;
        }
    }

    return AREA_FALLBACK[fallbackIndex % AREA_FALLBACK.length];
}

function serializeQuestion(entry) {
    return `  ${JSON.stringify(entry)}`;
}

function main() {
    const baseDir = __dirname;
    const allQuestions = [];
    const errors = [];

    for (const inputFile of INPUT_FILES) {
        const fullPath = path.join(baseDir, inputFile);

        if (!fs.existsSync(fullPath)) {
            errors.push(`No existe el archivo ${inputFile}`);
            continue;
        }

        const content = fs.readFileSync(fullPath, "utf8");
        const blocks = splitBlocks(content);

        for (const block of blocks) {
            const parsed = parseBlock(block);

            if (!parsed) {
                const id = block[0] || "bloque sin cabecera";
                errors.push(`No se pudo parsear ${inputFile}: ${id}`);
                continue;
            }

            const area = (inputFile == "lengua.txt") ? "Lengua" : inferArea(
                `${parsed.question}\n${parsed.options.join("\n")}`,
                allQuestions.length
            );

            allQuestions.push({
                q: parsed.question,
                options: parsed.options,
                answer: parsed.answer,
                area,
                source: inputFile,
            });
        }
    }

    const output = [
        "// Generado automáticamente por ./egel/generar_banco_egel.js",
        `const EGEL_QUESTIONS = [\n${allQuestions.map(serializeQuestion).join(",\n")}\n];`,
        "",
        'if (typeof window !== "undefined") {',
        "  window.questions = EGEL_QUESTIONS;",
        "}",
        "",
        'if (typeof module !== "undefined") {',
        "  module.exports = { questions: EGEL_QUESTIONS };",
        "}",
        "",
    ].join("\n");

    fs.writeFileSync(path.join(baseDir, OUTPUT_FILE), output, "utf8");

    console.log(`Generadas ${allQuestions.length} preguntas en ${OUTPUT_FILE}`);

    if (errors.length > 0) {
        console.warn(`Bloques con problemas: ${errors.length}`);
        for (const error of errors.slice(0, 20)) {
            console.warn(`- ${error}`);
        }
        if (errors.length > 20) {
            console.warn(`- ... y ${errors.length - 20} más`);
        }
    }
}

main();
