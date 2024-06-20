using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;


namespace Day1 {
    public class Program {
        public static string FilePath = "./inputs/one";
        public static string[] AllLines = GetInput();

        public static string[] GetInput() {
            return File.ReadAllLines(FilePath);
        } 

        public static void Main(string[] args) {
            List<char> numbersInLine;
            int totalSum = 0;

            foreach (string line in AllLines) {
                numbersInLine = new List<char>();

                foreach (char character in line) 
                    if (Char.IsDigit(character))
                        numbersInLine.Add(character);

                if (!numbersInLine.Any())
                    continue;

                int n;
                int.TryParse(
                    $"{numbersInLine.First()}{numbersInLine.Last()}",
                    out n
                );

                if (n.GetType() == typeof(int))
                    totalSum += n;
            }

            Console.WriteLine(totalSum);
        }
    }
}
