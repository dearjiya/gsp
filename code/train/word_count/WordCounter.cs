using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Train
{
    class WordCounter : ICounter
    {
        char[] delimiters = new char[] { ' ', '\r', '\n' };


        public int count()
        {
            int count = 0;
            FileReader fileReader = new FileReader();
            string[] lines = fileReader.fileRead();

            System.Console.WriteLine("=== FileRead === ");
            foreach (string line in lines)
            {
                count += line.Split(delimiters, StringSplitOptions.RemoveEmptyEntries).Length;
                Console.WriteLine("count: " + count);
            }
            return count;
        }

        public int uniqueWordCount()
        {
            int uCount = 0;

            FileReader fileReader = new FileReader();
            var lines = fileReader.fileRead();

            foreach (var line in lines)
            {
                HashSet<string> uniqueWords = new HashSet<string>(line.Split(delimiters, StringSplitOptions.RemoveEmptyEntries), StringComparer.OrdinalIgnoreCase);
                uCount += uniqueWords.Count;
            }

            return uCount;
        }

    }
}
