using System;
using System.Text;
using System.Net.Sockets;

class Program
{
    public const string SERVER_ADDRESS = "192.168.12.144";
    public const int SERVER_PORT = 20081;

    private TcpClient client = null;
    private int writeLength = 0;
    private int readLength = 0;
    byte[] readBuf = null;

    Program()
    {
        client = new TcpClient();
        client.SendTimeout = 1000;
        client.ReceiveTimeout = 1000;
        client.NoDelay = true;

        writeLength = 0;
        readLength = 0;
        readBuf = new byte[1024];
    }

    private void PingPong()
    {
        client.Connect(SERVER_ADDRESS, SERVER_PORT);
        string hello = "hello world.\n";
        byte[] writeBuf = Encoding.UTF8.GetBytes(hello);

        while (true)
        {
            try
            {
                client.GetStream().Write(writeBuf, 0, writeBuf.Length);
                writeLength += writeBuf.Length;

                int len = client.GetStream().Read(readBuf, 0, readBuf.Length);
                readLength += len;

                for (int i = 0; i < len; ++i)
                {
                    Console.Write((char)readBuf[i]);
                }
                Console.WriteLine("readLength = {0}, writeLength = {1}.\n", readLength, writeLength);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }

    static void Main(string[] args)
    {
        Program p = new Program();
        p.PingPong();
    }
}

