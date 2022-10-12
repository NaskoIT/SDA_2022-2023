using System;
using System.Linq;

namespace OverlappingIntervals
{
    class Program
    {
        static void Main(string[] args)
        {
            int[][] intervals = new int[4][];
            intervals[0] = new int[] { 1, 11 };
            intervals[1] = new int[] { 2, 12 };
            intervals[2] = new int[] { 11, 22 };
            intervals[3] = new int[] { 1, 100 };

            int result = EraseOverlapIntervals(intervals);
            Console.WriteLine(result);
        }

        public static int EraseOverlapIntervals(int[][] intervals)
        {
            intervals = intervals.OrderBy(x => x[1]).ToArray();
            int intervalsAdd = 1;
            int[] lastInterval = intervals[0];

            for (int i = 1; i < intervals.Length; i++)
            {
                int[] current = intervals[i];

                if (lastInterval[1] <= current[0])
                {
                    intervalsAdd++;
                    lastInterval = current;
                }
            }

            return intervals.Length - intervalsAdd;
        }
    }
}
