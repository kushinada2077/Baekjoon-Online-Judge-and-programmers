const fs = require("fs").readFileSync("/dev/stdin").toString().trim().split("");
const n = fs.length;
let cnt = 0;
for (let i = 0; i < n; i++) {
    if (fs[i] != "!") {
        if (fs[i] == "c") {
            if (i + 1 < n && fs[i + 1] == "=") {
                fs[i] = "!";
                fs[i + 1] = "!";
                cnt += 1;
            } else if (i + 1 < n && fs[i + 1] == "-") {
                fs[i] = "!";
                fs[i + 1] = "!";
                cnt += 1;
            }
        } else if (fs[i] == "d") {
            if (i + 1 < n && fs[i + 1] == "z") {
                if (i + 2 < n && fs[i + 2] == "=") {
                    fs[i] = "!";
                    fs[i + 1] = "!";
                    fs[i + 2] = "!";
                    cnt += 1;
                }
            } else if (i + 1 < n && fs[i + 1] == "-") {
                fs[i] = "!";
                fs[i + 1] = "!";
                cnt += 1;
            }
        } else if (fs[i] == "l") {
            if (i + 1 < n && fs[i + 1] == "j") {
                fs[i] = "!";
                fs[i + 1] = "!";
                cnt += 1;
            }
        } else if (fs[i] == "n") {
            if (i + 1 < n && fs[i + 1] == "j") {
                fs[i] = "!";
                fs[i + 1] = "!";
                cnt += 1;
            }
        } else if (fs[i] == "s") {
            if (i + 1 < n && fs[i + 1] == "=") {
                fs[i] = "!";
                fs[i + 1] = "!";
                cnt += 1;
            }
        } else if (fs[i] == "z") {
            if (i + 1 < n && fs[i + 1] == "=") {
                fs[i] = "!";
                fs[i + 1] = "!";
                cnt += 1;
            }
        }
    }
}

let newfs = fs.filter((v) => v !== "!" && v !== "-" && v !== "=");
cnt += newfs.length;
console.log(cnt);