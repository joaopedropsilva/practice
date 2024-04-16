import fs from 'node:fs'
import rdl from 'node:readline'
import path from 'node:path'

export async function readInput(file_name: string): Promise<string[][] | []> {
    const INPUT_PATH = path.join(__dirname, `../${file_name}`);
    const input = fs.createReadStream(INPUT_PATH, { encoding: 'utf-8' });
    const output: string[] = [];

    return await new Promise((resolve, reject) => {
        try {
            const lineReader = rdl.createInterface({ input });

            lineReader.on('line', (line: string) => {
                output.push(line);
            });

            return lineReader.on('close', () => {
                return resolve(output.map((line: string) => line.split(' ')));
            });
        } catch (error) {
            return reject(error);
        }
    });
}

const pOneTable = {
    A: 1,
    B: 2,
    C: 3,
}

const pTwoTable = {
    X: 1,
    Y: 2,
    Z: 3,
}

// Error must be here
function evaluateLineScore(line: string[]): number {
    const fpScore = pOneTable[line[0] as keyof typeof pOneTable]; 
    const spScore = pTwoTable[line[1] as keyof typeof pTwoTable]; 

    if (fpScore === spScore) {
        return 3 + spScore;
    } else if (fpScore < spScore) {
        return 6 + spScore;
    }

    return spScore;
}

(() => {
    let total = 0;

    readInput('../inputs/two').then((lines) => {
        lines.forEach(line => {
            total += evaluateLineScore(line);
        });

        console.log(total);
    });
})();

