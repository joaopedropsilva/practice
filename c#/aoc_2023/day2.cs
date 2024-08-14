namespace Day2 {
    using System;
    using System.Collections.Generic;
    using System.IO;

    public class Program {
        private static string InputPath = "./inputs/two";

        public static void Main() {
            string[] samples = File.ReadAllLines(InputPath);
            int nRedCubes = 12;
            int nGreenCubes = 13;
            int nBlueCubes = 14;

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



                // check if possible for each round, if not break the loop and continue
                foreach (string r in rounds) {
                    string[] rInfo = r.Split(",");

                    List<KeyValuePair<string, int>> cubesAndNumber =
                        new List<KeyValuePair<string, int>>();
                    for (int i = 0; i < rInfo.Length; i++) {
                        rInfo[i] = rInfo[i].Trim();
                    }

                    foreach (string ri in rInfo) {
                        int nCubes;
                        int.TryParse(ri[0].ToString(), out nCubes);

                        cubesAndNumber
                            .Add(
                                new KeyValuePair<string, int>
                                (
                                    ri.Substring(2),
                                    nCubes
                                )
                            );

                        // Trim kvp keys
                        // Check output, seems strange
                        cubesAndNumber
                            .ForEach(cn => {
                                Console.WriteLine(cn.ToString());
                            });
                    }
                }

                break;
            }
        }
    }
}
