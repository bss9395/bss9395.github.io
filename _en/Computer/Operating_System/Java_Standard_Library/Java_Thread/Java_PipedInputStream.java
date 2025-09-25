/* Java_PipedInputStream.java
Author: bss9395
Update: 2025/09/24T21:03:00+08@China-GuangDong-ZhanJiang+08
*/

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

class SendThread implements Runnable {
    private PipedOutputStream _output;
    public SendThread() {
        _output = new PipedOutputStream();
    }

    @Override
    public void run() {
        try {
            for(int x = 0; x < 3; x += 1) {
                _output.write(("[" + Thread.currentThread().getName() + "第" + (x + 1) +"发送消息]\n").getBytes());
                System.out.println("_output.flush()");
                _output.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        try {
            _output.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public PipedOutputStream getOuput() {
        return this._output;
    }
}

class ReceiveThread implements Runnable {
    private PipedInputStream _input;
    public ReceiveThread() {
        _input = new PipedInputStream();
    }

    @Override
    public void run() {
        try {
            byte[] data = new byte[1024];
            int len = 0;
            ByteArrayOutputStream bos = new ByteArrayOutputStream();
            while((len = _input.read(data)) != -1) {
                System.out.println("_input.read()");
                bos.write(data, 0, len);
            }
            System.out.println("{" + Thread.currentThread().getName() + "接收消息}\n" + new String(bos.toByteArray()));
            bos.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        try {
            _input.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public PipedInputStream getInput() {
        return _input;
    }
}

public class Java_PipedInputStream {
    static public void main(String[] args) throws IOException {
        SendThread send = new SendThread();
        ReceiveThread receive = new ReceiveThread();
        send.getOuput().connect(receive.getInput());
        new Thread(send, "消息发送线程").start();
        new Thread(receive, "消息接收线程").start();
    }
}
