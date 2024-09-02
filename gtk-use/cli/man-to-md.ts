#!/home/jaipal001/.bun/bin/bun

import { readFileSync } from "fs";
import process from "process";

let src = process.cwd() + "/" + process.argv[2];
let dest = process.cwd() + "/" + process.argv[3];

console.log(src, dest);

let srcContent = readFileSync(src).toString();
let outContent: string;

while (srcContent.includes("\n")) srcContent = srcContent.replace("\n", " ");

let nameArray = srcContent.match(/.SH NAME \w+/);
let name = nameArray![0].split(" ")[2];
console.log(name);
