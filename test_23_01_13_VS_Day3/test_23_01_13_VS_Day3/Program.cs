using System;

internal class Program
{
    private static void Main(string[] args)
    {

        Console.Write("请输入学生总数：");
        int n = int.Parse(Console.ReadLine());
        int[] arr;

        arr = new int[n];

        Console.Write("请输入学生成绩：");
        for (int i = 0; i < arr.Length; i++)
        {
            arr[i] = int.Parse(Console.ReadLine());

        }

        Console.WriteLine("学生的成绩为：");

        for (int i = 0; i < arr.Length; i++)
        {
            Console.Write(arr[i] + " " );

        }

    }
}