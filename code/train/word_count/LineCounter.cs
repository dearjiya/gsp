using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace Train
{
    class LineCounter : ICounter
    {
        public int count()
        {
            int count = 0;
            FileReader fileReader = new FileReader();
            string[] lines = fileReader.fileRead();
            count = lines.Length;

            return count;
        }

        public int isMatchCount(string str, string file)
        {
            bool boolMatch= false;
            int matchCount = 0;
            FileReader fileReader = new FileReader();
            string[] datas = fileReader.fileRead();
            foreach(var data in datas)
            {
                boolMatch = Regex.IsMatch(data, @"^" + str);
                if(boolMatch)
                {
                    matchCount += 1;
                }
                boolMatch = false;
            }

            return matchCount;
        }
    }
}
