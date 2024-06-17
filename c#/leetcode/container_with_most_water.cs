using System;
using System.Collections.Generic;
using System.Linq;

namespace ContainerWithMostWaterChallenge {
    public class Program {
        public static int[] GetHeights() {
            string input = Console.ReadLine();
            List<int> heights = new List<int>();
            
            int h;
            for (int i = 0; i < input.Length; i++) {
                bool isParseOk =
                    int.TryParse(input[i].ToString(), out h);

                if (isParseOk) {
                    heights.Add(h);
                }
            }

            return heights.ToArray();
        }

        public static int MaxArea(int[] height) {
            int distance = 0;
            int boundingHeight = 0;

            int currentBh;
            int currentDistance;
            for (int i = 0; i < height.Length; i++) {
                for (int j = i + 1; j < height.Length; j++) {
                    currentBh =
                        height[i] >= height[j] 
                            ? height[j] 
                            : height[i];
                    currentDistance = j - i;

                    if ((boundingHeight > currentBh)
                        && (boundingHeight - currentDistance) > 1)
                            continue;

                    boundingHeight = currentBh;
                    distance = currentDistance;
                }
            }

            return boundingHeight * distance;
        }

        public static void Main(string[] args) {
            int[] heights = GetHeights();

            Console.WriteLine(MaxArea(heights));
        }
    }
}
