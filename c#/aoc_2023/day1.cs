using System;
using System.IO;


namespace Day1 {
    public class Program {
        public static string FilePath = "./inputs/one";
        public static string[] AllLines = GetInput();

        public static string[] GetInput() {
            return File.ReadAllLines(FilePath);
        } 

        public static int Solve() {
            List<char> numbersInLine = new List<char>();
            int totalSum = 0;

            foreach (string line in AllLines) {
                foreach (char character in line) 
                    if (Char.IsLetterOrDigit(character))
                        numbersInLine.Add(character);

                 int numberForLine;
                    int.TryParse(
                        new String(numbersInLine.First() + numbersInLine.Last()),
                        out numberForLine
                    );

                if (typeof(numberForLine) == int)
                    totalSum += numberForLine;
            }

            return totalSum;

        }

        public static void Main(string[] args) {
        }
    }
}
