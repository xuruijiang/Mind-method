// See https://aka.ms/new-console-template for more information
//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;


namespace Day01
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //Console.WriteLine("Hello, World!");
            //string s = Console.ReadLine();
            //Console.WriteLine(s);

            //Console.Title = "俺的第一个程序";//Title是属性

            string gunName = "AK47";
            int numberClips = 0;
            int numberCurrentMagazineBullets = 0;
            int numberOfBulletsRemaining = 0;

            gunName = Console.ReadLine();
            numberClips = int.Parse(Console.ReadLine());
            numberCurrentMagazineBullets = int.Parse(Console.ReadLine());
            numberOfBulletsRemaining = int.Parse(Console.ReadLine());

            Console.WriteLine("枪名：" + gunName + "   剩余弹夹数：" + numberClips + "   当前弹夹子弹数： " + numberCurrentMagazineBullets + "   剩余子弹数："+ numberOfBulletsRemaining);
        }
    }
}