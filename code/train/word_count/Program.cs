using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Train
{
    class Program
    {
        static void Main(string[] args)
        {
            LineCounter counter = new LineCounter();
            int res = counter.isMatchCount("hello", "linetest.txt");
            Console.WriteLine(res);
            Console.ReadLine();
        }
    }
}
