using System;
using System.Text;
using System.Net.Sockets;
using System.Threading;

class Program
{
    public const string SERVER_ADDRESS = "192.168.12.144";
    public const int SERVER_PORT = 20081;

    private TcpClient client = null;
    private int writeLength = 0;
    private int readLength = 0;
    byte[] writeBuf = null;
    byte[] readBuf = null;

    Program()
    {
        client = new TcpClient();
        client.SendTimeout = 1000;
        client.ReceiveTimeout = 1000;
        client.NoDelay = true;

        writeLength = 0;
        readLength = 0;
        string hello = "Hello World.\n";
        writeBuf = Encoding.UTF8.GetBytes(hello);
        readBuf = new byte[1024];
    }

    private void OnRead(IAsyncResult ar)
    {
        int len = client.GetStream().EndRead(ar);
        readLength += len;

        for (int i = 0; i < len; ++i)
        {
            Console.Write((char)readBuf[i]);
        }

        client.GetStream().BeginWrite(writeBuf, 0, writeBuf.Length, new AsyncCallback(OnWrite), null);
    }

    private void OnWrite(IAsyncResult ar)
    {
        client.GetStream().EndWrite(ar);
        client.GetStream().BeginRead(readBuf, 0, readBuf.Length, new AsyncCallback(OnRead), null);
    }

    private void OnConnect(IAsyncResult ar)
    {
        client.EndConnect(ar);
        client.GetStream().BeginWrite(writeBuf, 0, writeBuf.Length, new AsyncCallback(OnWrite), null);
        writeLength += writeBuf.Length;
    }

    private void PingPong()
    {
        client.BeginConnect(SERVER_ADDRESS, SERVER_PORT, new AsyncCallback(OnConnect), null);
    }

    static void Main(string[] args)
    {
        Program p = new Program();
        p.PingPong();
        while (true)
        {
            Thread.Sleep(1000);
            Console.WriteLine("readLength = {0}, writeLength = {1}.\n", p.readLength, p.writeLength);
        }
    }
}

