// FIX CODE
namespace Day2 {
    using System;
    using System.Collections.Generic;
    using System.IO;

    public class Program {
        private static string InputPath = "./inputs/two";

        public static void Main() {
            string[] cubeColors = {"red", "green", "blue"};
            int[] cubeAmountLimit = {12, 13, 14};
            HashSet<int> validGameIds = new HashSet<int>();
            List<KeyValuePair<string, int>> maxAmountByColor =
                new List<KeyValuePair<string, int>>();

            for (int i = 0; i < cubeColors.Length; i++) {
                maxAmountByColor.Add(
                    new KeyValuePair<string, int>
                    (
                        cubeColors[i],
                        cubeAmountLimit[i]
                    )
                );
            }

            string[] samples = File.ReadAllLines(InputPath);
            foreach (string sample in samples) {
                // sample processing
                string[] sampleSplit = sample.Split(':');
                string[] gameInfo = new string[(int)sampleSplit.Length];
                bool isGameValid = true;

                for (int i = 0; i < gameInfo.Length; i++) {
                    gameInfo[i] = sampleSplit[i].Trim();
                }

                int id;
                int.TryParse(gameInfo[0].Split()[1], out id);

                string[] rounds = gameInfo[1].Split(";");
                for (int i = 0; i < rounds.Length; i++) {
                    rounds[i] = rounds[i].Trim();
                }

                // round processing
                List<KeyValuePair<string, int>> colorAndNumber =
                    new List<KeyValuePair<string, int>>();
                foreach (string r in rounds) {
                    string[] roundColorsAndNumber = r.Split(",");

                    for (int i = 0; i < roundColorsAndNumber.Length; i++) {
                        roundColorsAndNumber[i] =
                            roundColorsAndNumber[i].Trim();
                    }

                    foreach (string rcn in roundColorsAndNumber) {
                        int nCubes;
                        int.TryParse(
                                rcn.Substring(0, rcn.IndexOf(" ")).ToString(),
                                out nCubes
                            );

                        colorAndNumber
                            .Add(
                                new KeyValuePair<string, int>
                                (
                                    rcn.Substring(rcn.IndexOf(" ")).Trim(),
                                    nCubes
                                )
                            );
                    }

                    foreach (KeyValuePair<string, int> cn in colorAndNumber) {
                        KeyValuePair<string, int> maxFromCurrentColor =
                            maxAmountByColor.Find(c => c.Key == cn.Key); 

                        if (cn.Value > maxFromCurrentColor.Value) {
                            isGameValid = false;
                            break;
                        }
                    }

                    colorAndNumber.Clear();

                    if (!isGameValid)
                        break;

                    validGameIds.Add(id);
                }
            }

            int validGameIdsSum = 0;
            foreach (int id in validGameIds) {
                validGameIdsSum += id;
            }

            Console.WriteLine("Sum of valid game ids: {0}", validGameIdsSum);
        }
    }
}
