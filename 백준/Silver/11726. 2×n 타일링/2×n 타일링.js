const N = +require("fs").readFileSync("/dev/stdin").toString().trim();
const dp = Array.from({ length: N + 1 }, (v) => -1);
const MOD = 10007;

function f(x) {
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 2;
    }
    if (dp[x] != -1) {
        return dp[x];
    }

    return (dp[x] = (f(x - 1) + f(x - 2)) % MOD);
}

console.log(f(N));