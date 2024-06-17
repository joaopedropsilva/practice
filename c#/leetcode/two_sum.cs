using System;
c

namespace TwoSumChallenge {
	public class Program {
		public static int[] GetNums() {
			List<int> nums = new List<int>();
			string values = Console.ReadLine();

			for (int i = 0; i < values.Length; i++) {
				int val;
				bool isParseOk = 
					int.TryParse(values[i].ToString(), out val);

				if (isParseOk) {
					nums.Add(val);
				}
			}

			return nums.ToArray();
		}

		public static int[] TwoSum(int[] nums, int target) {
			if (nums.Length <= 1) return new int[] { 0 };

			for (int i = 0; i < nums.Length; i++) {
				for (int j = i; j < nums.Length; j++) {
					if (i == j) continue;

					if (nums[i] + nums[j] == target) {
						return new int[] { i, j };
					}
				}
			}

			return new int[] { };
		}

		static void Main(string[] args) {
			int[] nums = GetNums();
			int target = 6;

			int[] result = TwoSum(nums, target);

			Console.Write('[');
			for (int i = 0; i < result.Length; i++) {
				Console.Write(result[i] + ", ");
			}
			Console.Write(']');
		}

	}
}
