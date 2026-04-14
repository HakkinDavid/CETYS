#!/usr/bin/env node

const fs = require("fs");
const path = require("path");

const INPUT_FILES = ["casos.txt", "lengua.txt", "conceptos.txt", "sintéticas.txt"];
const OUTPUT_FILE = "banco_preguntas.js";
const SYNTHETIC_SOURCES = new Set(["sintéticas.txt"]);

const DEFAULT_CASOS_CLASSIFICATION = {
    area: "Desarrollo de software de aplicación",
    subarea: "Ingeniería de software",
    method: "source-default",
};

const SOURCE_AREA_MAP = {
    "lengua.txt": {
        area: "Lengua",
        subarea: null,
        method: "source-fixed",
    },
};

const CONCEPTOS_SUBAREA_MAP = {
    1: "Análisis y diseño de algoritmos",
    2: "Análisis y diseño de algoritmos",
    3: "Estructuras de datos",
    4: "Matemáticas discretas",
    5: "Lógica computacional",
    6: "Arquitectura de computadoras y sistemas operativos",
    7: "Compiladores",
    8: "Redes de computadoras",
    9: "Ingeniería de software",
    10: "Lenguajes de programación",
    11: "Bases de datos",
    12: "Seguridad informática",
    13: "Inteligencia artificial",
    14: "Inteligencia artificial",
    15: "Minería de datos",
    16: "Cómputo distribuido",
    17: "Cómputo distribuido",
    18: "Inteligencia artificial",
};

const SUBAREA_TO_AREA = {
    "Análisis y diseño de algoritmos": "Algoritmia",
    "Estructuras de datos": "Algoritmia",
    "Matemáticas discretas": "Algoritmia",
    "Lógica computacional": "Algoritmia",
    "Arquitectura de computadoras y sistemas operativos": "Desarrollo de software de base",
    "Compiladores": "Desarrollo de software de base",
    "Redes de computadoras": "Desarrollo de software de base",
    "Ingeniería de software": "Desarrollo de software de aplicación",
    "Lenguajes de programación": "Desarrollo de software de aplicación",
    "Bases de datos": "Desarrollo de software de aplicación",
    "Seguridad informática": "Desarrollo de software de aplicación",
    "Inteligencia artificial": "Soluciones de cómputo inteligente",
    "Minería de datos": "Soluciones de cómputo inteligente",
    "Cómputo distribuido": "Soluciones de cómputo inteligente",
};

const SUBAREA_RULES = [
    {
        subarea: "Compiladores",
        patterns: [
            /compilador(?:es)?/i,
            /an[aá]lisis l[eé]xico/i,
            /an[aá]lisis sint[aá]ctico/i,
            /\btokens?\b/i,
            /an[aá]lisis sem[aá]ntico/i,
            /c[oó]digo objeto/i,
            /\bl[re]\s*\(/i,
            /\bparser\b/i,
            /\bparseo\b/i,
            /\bgram[aá]tica\b/i,
            /contexto libre/i,
            /chomsky/i,
            /aut[oó]mata/i,
            /lenguaje regular/i,
            /libre de contexto/i,
            /expresiones regulares/i,
            /\bpl\/i\b/i,
            /tabla de s[ií]mbolos/i,
        ],
    },
    {
        subarea: "Bases de datos",
        patterns: [
            /base de datos/i,
            /\bdbms\b/i,
            /\bsql\b/i,
            /\bacid\b/i,
            /\bdurability\b/i,
            /\bisolation\b/i,
            /\batomicity\b/i,
            /\bconsistency\b/i,
            /\brelacional\b/i,
            /normaliz/i,
            /integridad referencial/i,
            /llaves? for[aá]neas?/i,
            /[íi]ndices?/i,
            /\bregistro(s)?\b/i,
            /archivo secuencial/i,
            /diccionario de datos/i,
            /interconecte correctamente con otras aplicaciones o bases de datos/i,
        ],
    },
    {
        subarea: "Seguridad informática",
        patterns: [
            /seguridad/i,
            /amenaza/i,
            /vulnerab/i,
            /riesgo/i,
            /auditor[ií]a/i,
            /trazabilidad/i,
            /control de acceso/i,
            /cifrad/i,
            /autentic/i,
            /\bmitm\b/i,
            /\bphishing\b/i,
            /\bmalware\b/i,
            /\bpharming\b/i,
            /\bconfidencialidad\b/i,
            /\bcsrf\b/i,
            /\bxss\b/i,
            /inyecci[oó]n/i,
        ],
    },
    {
        subarea: "Redes de computadoras",
        patterns: [
            /\bred(?:es)? de computadoras?\b/i,
            /\bred(?:es)?\b/i,
            /\bhttp\b/i,
            /\btcp\b/i,
            /\btcp\/ip\b/i,
            /\budp\b/i,
            /\bdns\b/i,
            /\barp\b/i,
            /\bicmp\b/i,
            /\bethernet\b/i,
            /\bosi\b/i,
            /\bp2p\b/i,
            /cliente-servidor/i,
            /\bvlan\b/i,
            /\bvpn\b/i,
            /\brouter\b/i,
            /protocolo(?:s)? de comunicaci[oó]n/i,
            /interoperabilidad/i,
        ],
    },
    {
        subarea: "Arquitectura de computadoras y sistemas operativos",
        patterns: [
            /arquitectura de computadoras/i,
            /sistema operativo/i,
            /\bmemoria\b/i,
            /\bprocesos?\b/i,
            /\blisto\b/i,
            /\bbloqueado\b/i,
            /\bejecutando\b/i,
            /\bterminado\b/i,
            /\bdeadlock\b/i,
            /round robin/i,
            /\bharvard\b/i,
            /von neumann/i,
            /\bhilos?\b/i,
            /\bthread\b/i,
            /planificaci[oó]n/i,
            /\bcpu\b/i,
            /\bhardware\b/i,
            /\bloader\b/i,
            /\blinker\b/i,
            /trabajo en un lote/i,
            /administrador de procesos/i,
        ],
    },
    {
        subarea: "Cómputo distribuido",
        patterns: [
            /c[oó]mputo distribuido/i,
            /sistema(?:s)? distribuido/i,
            /\bnodos?\b/i,
            /\bcap\b/i,
            /\bconsenso\b/i,
            /\braft\b/i,
            /\bquorum\b/i,
            /replicaci[oó]n/i,
            /particionado/i,
            /\bmapreduce\b/i,
            /hashing consistente/i,
            /distribuci[oó]n de nodos/i,
        ],
    },
    {
        subarea: "Minería de datos",
        patterns: [
            /miner[ií]a de datos/i,
            /\bclustering\b/i,
            /\bk-means\b/i,
            /\bextracci[oó]n de patrones\b/i,
            /\bdescubrir patrones\b/i,
            /\bdatos hist[oó]ricos\b/i,
        ],
    },
    {
        subarea: "Inteligencia artificial",
        patterns: [
            /inteligencia artificial/i,
            /machine learning/i,
            /aprendizaje autom[aá]tico/i,
            /\bsupervisado\b/i,
            /no supervisado/i,
            /refuerzo/i,
            /heur[ií]stica/i,
            /\bmodelo(s)?\b/i,
            /red(?:es)? neuronales?/i,
            /\bsvm\b/i,
            /\bnaive bayes\b/i,
            /\bpca\b/i,
            /\bembedding/i,
            /lenguaje natural/i,
            /capacidad de adaptaci[oó]n/i,
        ],
    },
    {
        subarea: "Análisis y diseño de algoritmos",
        patterns: [
            /an[aá]lisis de algoritmos/i,
            /dise[nñ]o de algoritmos/i,
            /\balgoritmo\b/i,
            /divide and conquer/i,
            /\bbig o\b/i,
            /\btheta\b/i,
            /\bomega\b/i,
            /programaci[oó]n din[aá]mica/i,
            /algoritmo voraz/i,
            /\ba\*\b/i,
            /\bcomplejidad\b/i,
            /\brecurs/i,
            /divide y vencer[aá]s/i,
            /\bbacktracking\b/i,
            /\bdijkstra\b/i,
            /\bprim\b/i,
            /\bkruskal\b/i,
            /\bbellman-ford\b/i,
            /\bfloyd/i,
        ],
    },
    {
        subarea: "Estructuras de datos",
        patterns: [
            /estructura(?:s)? de datos/i,
            /lista ligada/i,
            /\bpila\b/i,
            /\bcola\b/i,
            /lista enlazada/i,
            /\bheap\b/i,
            /tabla hash/i,
            /\bhash\b/i,
            /\b[aá]rbol(?:es)?\b/i,
            /\bmatriz\b/i,
        ],
    },
    {
        subarea: "Matemáticas discretas",
        patterns: [
            /matem[aá]ticas discretas/i,
            /teor[ií]a de grafos/i,
            /\bgrafo(?:s)?\b/i,
            /conjunto(?:s)?/i,
            /combinatoria(?:s)?/i,
            /relaciones entre objetos/i,
        ],
    },
    {
        subarea: "Lógica computacional",
        patterns: [
            /l[oó]gica proposicional/i,
            /l[oó]gica de primer orden/i,
            /inferencia basada en reglas/i,
            /proposiciones l[oó]gicas/i,
            /\bboolean/i,
            /\binvariante\b/i,
            /\bprecondici[oó]n\b/i,
            /\bpostcondici[oó]n\b/i,
        ],
    },
    {
        subarea: "Lenguajes de programación",
        patterns: [
            /lenguaje(?:s)? de programaci[oó]n/i,
            /lenguaje de alto nivel/i,
            /c[oó]digo fuente/i,
            /\bdeclarativo\b/i,
            /\bimperativo\b/i,
            /\bfuncional\b/i,
            /\bpoo\b/i,
            /encapsulamiento/i,
            /programaci[oó]n orientada a objetos/i,
            /software orientado a objetos/i,
            /\boo\b/i,
            /\bpl\/i\b/i,
        ],
    },
    {
        subarea: "Ingeniería de software",
        patterns: [
            /ingenier[ií]a de software/i,
            /\bpruebas?\b/i,
            /depuraci[oó]n/i,
            /debug/i,
            /\bsqa\b/i,
            /\bscm\b/i,
            /configuraci[oó]n/i,
            /requisitos?/i,
            /\bsrs\b/i,
            /mantenimiento/i,
            /reingenier[ií]a/i,
            /\bsdlc\b/i,
            /ciclo de vida/i,
            /gesti[oó]n de cambios/i,
            /casos de prueba/i,
            /validaci[oó]n/i,
            /verificaci[oó]n/i,
            /m[eé]tricas?/i,
            /defectos?/i,
            /riesgo t[eé]cnico/i,
            /riesgo del proyecto/i,
            /riesgo del negocio/i,
            /cohesi[oó]n/i,
            /acoplamiento/i,
            /\bcase\b/i,
            /proceso de software/i,
            /proceso unificado/i,
            /modularizaci[oó]n/i,
            /interfaz del m[oó]dulo/i,
            /prueba alfa/i,
            /prueba beta/i,
            /aceptaci[oó]n/i,
            /conjunto de actividades/i,
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
        if (/^(?:Numero|Número) de pregunta:\s*[\d.]+/i.test(line)) {
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
    const questionNumberMatch = lines[0].match(/^(?:Numero|Número) de pregunta:\s*([\d.]+)/i);
    const parsed = {
        id: questionNumberMatch ? questionNumberMatch[1] : null,
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

    if (!parsed.id || !question || options.length < 2 || answer < 0) {
        return null;
    }

    return {
        id: parsed.id,
        question,
        options,
        answer,
    };
}

function getAreaFromSubarea(subarea) {
    return SUBAREA_TO_AREA[subarea] ?? null;
}

function classifyConceptos(entry) {
    const majorBlock = Number(String(entry.id).split(".")[0]);
    const subarea = CONCEPTOS_SUBAREA_MAP[majorBlock] ?? null;

    if (!subarea) {
        return null;
    }

    return {
        area: getAreaFromSubarea(subarea),
        subarea,
        method: "conceptos-map",
    };
}

function countMatches(text, patterns) {
    return patterns.reduce((count, pattern) => count + (pattern.test(text) ? 1 : 0), 0);
}

function classifyByRules(entry) {
    const questionText = entry.question;
    const optionsText = entry.options.join(" ");

    const scores = SUBAREA_RULES.map((rule) => {
        const score = countMatches(questionText, rule.patterns) * 3 + countMatches(optionsText, rule.patterns);
        return { subarea: rule.subarea, score };
    }).filter((item) => item.score > 0);

    if (scores.length === 0) {
        return null;
    }

    scores.sort((a, b) => b.score - a.score);
    const best = scores[0];

    return {
        area: getAreaFromSubarea(best.subarea),
        subarea: best.subarea,
        method: "keyword-score",
        score: best.score,
    };
}

function classifyEntry(inputFile, entry) {
    if (SOURCE_AREA_MAP[inputFile]) {
        return SOURCE_AREA_MAP[inputFile];
    }

    if (inputFile === "conceptos.txt") {
        return classifyConceptos(entry) ?? DEFAULT_CASOS_CLASSIFICATION;
    }

    if (inputFile === "casos.txt") {
        return classifyByRules(entry) ?? DEFAULT_CASOS_CLASSIFICATION;
    }

    if (isSyntheticSource(inputFile)) {
        return classifyByRules(entry) ?? DEFAULT_CASOS_CLASSIFICATION;
    }

    return null;
}

function isSyntheticSource(inputFile) {
  return SYNTHETIC_SOURCES.has(inputFile) || /synthetic|sint[eé]t/i.test(inputFile);
}

function serializeQuestion(entry) {
    return `  ${JSON.stringify(entry)}`;
}

function main() {
    const baseDir = __dirname;
    const allQuestions = [];
    const errors = [];
    const stats = {};

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

            const classification = classifyEntry(inputFile, parsed);

            if (!classification?.area) {
                errors.push(`No se pudo clasificar ${inputFile}: ${parsed.id}`);
                continue;
            }

            const questionEntry = {
                id: parsed.id,
                q: parsed.question,
                options: parsed.options,
                answer: parsed.answer,
                area: classification.area,
                subarea: classification.subarea,
                synthetic: isSyntheticSource(inputFile),
                source: inputFile,
            };

            allQuestions.push(questionEntry);

            const statKey = `${questionEntry.area} :: ${questionEntry.subarea ?? "Sin subárea"}`;
            stats[statKey] = (stats[statKey] ?? 0) + 1;
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
    console.log("Distribución por área/subárea:");
    for (const [key, value] of Object.entries(stats).sort((a, b) => a[0].localeCompare(b[0], "es"))) {
        console.log(`- ${key}: ${value}`);
    }

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
