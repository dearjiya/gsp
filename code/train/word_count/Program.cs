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
            Counter counter = new Counter();
            int res = counter.uniqueWordCount();
            Console.WriteLine(res);
            Console.ReadLine();
        }
    }
}
