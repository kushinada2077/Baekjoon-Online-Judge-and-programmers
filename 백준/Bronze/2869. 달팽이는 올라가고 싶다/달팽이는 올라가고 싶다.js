const [a, b, c] = require("fs")
    .readFileSync("/dev/stdin")
    .toString()
    .trim()
    .split(" ")
    .map((v) => +v);

console.log(Math.floor((c - b - 1) / (a - b)) + 1);