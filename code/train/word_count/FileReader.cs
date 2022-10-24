using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Train
{
    class FileReader
    {
        void fileRead(string address)
        {
            var filePath = @"D:\dearjiya\gsp\code\train\word_count\data\helloworld.txt";
            if(File.Exists(filePath))
            {
                using(var reader = new StreamReader(filePath, Encoding.UTF8))
                {
                    while(!reader.EndOfStream)
                    {
                        var line = reader.ReadLine();
                        Console.WriteLine(line);
                    }
                }
            }
        }

        /// <summary>
        /// ReadAllLines라는 정적 메서드는 모든 행을 읽어들이고 그결과를 string[] 형으로 반환한다
        /// 거대한 텍스트 파일이라면 끝까지 읽는데 처리 지연이 발생하고 메모리를 압박하므로 주의해야한다
        /// 이 메서드는 작은 파일 전용
        /// </summary>
        public string[] fileRead()
        {
            var filePath = @"D:\dearjiya\gsp\code\train\word_count\data\helloworld.txt";
            var lines = File.ReadAllLines(filePath, Encoding.UTF8);
            //foreach(var line in lines)
            //{
            //    Console.WriteLine(line);
            //}
            return lines;
        }

        /// <summary>
        /// 확인필요 ㅠㅠ
        /// </summary>
        /// <returns></returns>
        public IEnumerable<string> improvedFileRead()
        {
            var filePath = @"D:\dearjiya\gsp\code\train\word_count\data\helloworld.txt";
            var lines = File.ReadLines(filePath, Encoding.UTF8);
            return lines;
        }
    }
}
