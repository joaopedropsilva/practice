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

function findMostCaloriesElf(buffer: string[][]): number {
    const numbers = buffer.map(item => parseInt(item[0]));

    let sum = 0;
    let biggerSum = 0;
    let lo = 0;
    for (let i = 0; i < numbers.length; ++i) {
        if (Number.isNaN(numbers[i])) {
            sum = numbers.slice(lo, i).reduce((partialSum, acc) => partialSum + acc, 0);
            lo = i + 1;
        }

        if (i === numbers.length - 1){
            sum = numbers.slice(lo, i + 1).reduce((partialSum, acc) => partialSum + acc, 0);

        }

        if (sum > biggerSum) {
            biggerSum = sum;
        }
    }

    return biggerSum;
}

(() => {
    readInput('../inputs/one').then((buffer) => {
        const result = findMostCaloriesElf(buffer) 
        console.log(result)
    });
})();


