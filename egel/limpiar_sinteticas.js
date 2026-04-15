#!/usr/bin/env node

const fs = require("fs");
const path = require("path");

const DEFAULT_INPUT = "sintéticas.txt";
const DEFAULT_OUTPUT = "sintéticas.txt";

function normalizeText(text) {
  return text.replace(/\r\n?/g, "\n").trim();
}

function splitBlocks(content) {
  return normalizeText(content)
    .split(/(?=^Numero de pregunta:\s*[\d.]+)/m)
    .map((block) => block.trim())
    .filter(Boolean);
}

function parseBlock(block) {
  const lines = block.split("\n");
  const questionMatch = block.match(/^Pregunta:\s*(.*)$/m);
  const answerMatch = block.match(/^Respuesta correcta:\s*([A-Z])/m);
  const options = [];

  for (const line of lines) {
    const optionMatch = line.match(/^([A-Z])[):]\s*(.*)$/);
    if (optionMatch) {
      options.push({
        label: optionMatch[1],
        text: optionMatch[2].trim(),
      });
    }
  }

  return {
    question: questionMatch ? questionMatch[1].trim() : "",
    answer: answerMatch ? answerMatch[1] : "",
    options,
    raw: block,
  };
}

function buildSignature(parsed) {
  const optionsSignature = parsed.options
    .map((option) => `${option.label}:${option.text}`)
    .join("|");

  return [
    parsed.question.replace(/\s+/g, " ").trim(),
    optionsSignature.replace(/\s+/g, " ").trim(),
    parsed.answer,
  ].join("||");
}

function renumberBlock(block, index) {
  return block.replace(
    /^Numero de pregunta:\s*[\d.]+/m,
    `Numero de pregunta: ${index + 1}`
  );
}

function main() {
  const baseDir = __dirname;
  const inputFile = process.argv[2] ?? DEFAULT_INPUT;
  const outputFile = process.argv[3] ?? DEFAULT_OUTPUT;
  const inputPath = path.resolve(baseDir, inputFile);
  const outputPath = path.resolve(baseDir, outputFile);

  if (!fs.existsSync(inputPath)) {
    console.error(`No existe el archivo de entrada: ${inputPath}`);
    process.exit(1);
  }

  const content = fs.readFileSync(inputPath, "utf8");
  const blocks = splitBlocks(content);
  const uniqueBlocks = [];
  const seen = new Set();

  for (const block of blocks) {
    const parsed = parseBlock(block);
    const signature = buildSignature(parsed);

    if (!parsed.question || !parsed.answer || parsed.options.length < 2) {
      continue;
    }

    if (seen.has(signature)) {
      continue;
    }

    seen.add(signature);
    uniqueBlocks.push(block);
  }

  const output = uniqueBlocks
    .map((block, index) => renumberBlock(block, index))
    .join("\n\n");

  fs.writeFileSync(outputPath, `${output}\n`, "utf8");

  console.log(`Entrada: ${blocks.length} bloques`);
  console.log(`Salida: ${uniqueBlocks.length} bloques únicos`);
  console.log(`Duplicados eliminados: ${blocks.length - uniqueBlocks.length}`);
  console.log(`Archivo generado: ${outputPath}`);
}

main();
