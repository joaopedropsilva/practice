namespace Day2 {
    using System;
    using System.Collections.Generic;
    using System.IO;

    public class Program {
        private static string InputPath = "./inputs/two";

        public static void Main() {
            string[] samples = File.ReadAllLines(InputPath);
            List<int> validGameIds = new List<int>();

            string[] cubeColors = {"red", "green", "blue"};
            int[] cubeAmountLimit = {12, 13, 14};

            List<KeyValuePair<string, int>> cubeLimits =
                new List<KeyValuePair<string, int>>();

            for (int i = 0; i < cubeColors.Length; i++) {
                cubeLimits.Add(
                    new KeyValuePair<string, int>
                    (
                        cubeColors[i],
                        cubeAmountLimit[i]
                    )
                );
            }


            foreach (string sample in samples) {
                string[] sampleSplit = sample.Split(':');
                string[] gameInfo = new string[(int)sampleSplit.Length];

                for (int i = 0; i < gameInfo.Length; i++) {
                    gameInfo[i] = sampleSplit[i].Trim();
                }

                int id;
                int.TryParse(gameInfo[0].Split()[1], out id);

                string[] rounds = gameInfo[1].Split(";");
                for (int i = 0; i < rounds.Length; i++) {
                    rounds[i] = rounds[i].Trim();
                }

                foreach (string r in rounds) {
                    string[] rInfo = r.Split(",");

                    List<KeyValuePair<string, int>> cubesAndNumber =
                        new List<KeyValuePair<string, int>>();
                    for (int i = 0; i < rInfo.Length; i++) {
                        rInfo[i] = rInfo[i].Trim();
                    }

                    foreach (string ri in rInfo) {
                        int nCubes;
                        int.TryParse(
                                ri.Substring(0, ri.IndexOf(" ")).ToString(),
                                out nCubes
                            );

                        cubesAndNumber
                            .Add(
                                new KeyValuePair<string, int>
                                (
                                    ri.Substring(ri.IndexOf(" ")).Trim(),
                                    nCubes
                                )
                            );
                    }

                    cubesAndNumber
                        .ForEach(cn => {
                                KeyValuePair<string, int> currentCube =
                                    cubesAndNumber.Find(x => x.Key == cn.Key);
                                KeyValuePair<string, int> limit =
                                    cubeLimits.Find(x => x.Key == cn.Key);

                                Console.WriteLine(currentCube.Value);
                                if (currentCube.Value <= limit.Value)
                                    validGameIds.Add(id);
                        });

                    cubesAndNumber.Clear();
                }

                break;
            }
        }
    }
}
