import java.io.*;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
class filecopy
{
	public static void main(String[] args) throws IOException
	{
		FileInputStream fin = new FileInputStream(args[0]);
		FileChannel fc = fin.getChannel();
		FileOutputStream fout1 = new FileOutputStream(args[1]);
		FileOutputStream fout2 = new FileOutputStream(args[2]);
		FileChannel fc_out1 = fout1.getChannel();
		FileChannel fc_out2 = fout2.getChannel();
		ByteBuffer buffer = ByteBuffer.allocate(1024);
		
		
		while(fc.read(buffer)>0)
		{
			buffer.flip();
			fc_out1.write(buffer);
			buffer.flip();
			fc_out2.write(buffer);
			buffer.clear();
		}
		fc.close();	
		fc_out1.close();
		fc_out2.close();
    }
}






		/*
        RandomAccessFile aFile = new RandomAccessFile(args[0], "r");
		Ran
        FileChannel inChannel = aFile.getChannel();
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        while(inChannel.read(buffer) > 0)
        {
            buffer.flip();
            for (int i = 0; i < buffer.limit(); i++)
            {
                System.out.print((char) buffer.get());
            }
            buffer.clear(); // do something with the data and clear/compact it.
        }
        inChannel.close();
        aFile.close();*/
