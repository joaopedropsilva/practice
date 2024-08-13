namespace Day2 {
    using System;
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

                int gameId;
                int.TryParse(gameInfo[0].Split()[1], out gameId);

                int j = 0;
                while (j < gameInfo[1].Length) {
                    int hi = gameInfo[1].IndexOf(";");
                    string target = gameInfo[1].Substring(j, hi);

                    Console.WriteLine(target);
                    gameInfo[1] = gameInfo[1].Remove(j, hi);

                    j = hi;
                }

                Console.WriteLine(gameInfo[1]);

                break;
            }
        }
    }
}
