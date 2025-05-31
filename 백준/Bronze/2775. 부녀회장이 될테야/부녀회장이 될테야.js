const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
for (let i = 1; i < 2 * +input[0]; i += 2) {
    const [k, n] = [Number(input[i]), Number(input[i + 1])];
    const arr = Array.from({ length: 15 }, () => Array.from({ length: 15 }, () => 0));
    for (let i = 1; i < 15; ++i) {
        arr[0][i] = i;
    }
    for (let i = 1; i < 15; ++i) {
        for (let j = 1; j < 15; ++j) {
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1];
        }
    }
    console.log(arr[k][n]);
}