

internal class Program
{
    private static void Main(string[] args)
    {
        Console.WriteLine("你知道吗");
        int m = int.Parse(Console.ReadLine());
        Console.WriteLine(m);

        string str = string.Format("我的岁数：{0}", m);
        Console.WriteLine(str);
    }
}