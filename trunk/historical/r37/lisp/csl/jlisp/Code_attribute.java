import java.io.*;

public class Code_attribute extends Attribute_info
{
    short    max_stack;
    short    max_locals;
    int      code_length = 0;
    byte[]   code = new byte[0];
    short    exception_table_length = 0;

    /* IGNORE EXCEPTIONS
        short start_pc;       // shall I introduce a new type for this?
        short end_pc;         // no exceptions for any of Trivial.java
        short handler_pc;
        short catch_type;
        exception_table[];    //should be [exception_table_length]
    */

    short attributes_count = (short)0;
    byte attributes[];
    //should be Attribute_info attributes[attributes_count]
    //but ignoring LineNumberTable here


    void setStackLocals(short stack, short locals)
    {
        max_stack  = stack;
        max_locals = locals;
    }
    
		/*
    void addInstruction(byte instr)
    {
        byte[] codeTemp = new byte[code.length+1];

        for (int i=0; i<code.length; i++)
            codeTemp[i] = code[i];

        codeTemp[code.length] = instr;
        code_length++;

        code = new byte[codeTemp.length];
        code = codeTemp;
    }
    */
		
		void addInstruction(byte instr, byte args[])
    {
        byte[] codeTemp = new byte[code.length+args.length+1];

        for (int i=0; i<code.length; i++)
            codeTemp[i] = code[i];        // copy code to codeTemp

        codeTemp[code.length] = instr;    // add instruction
        code_length++;

        for (int i=0; i<args.length; i++)
        {   codeTemp[i+code.length+1] = args[i];
            code_length++;
        }

        code = new byte[codeTemp.length];
        code = codeTemp;
    }

		void addInstruction(byte instr) //no args
		{
			byte[] emptyarray = new byte[] {};
			addInstruction(instr, emptyarray);
		}
		
		void addInstruction(byte instr, byte b) //byte arg
		{
			addInstruction(instr, ByteArray.byteToByteArray(b));
		}

		void addInstruction(byte instr, short s) //short arg
		{
			addInstruction(instr, ByteArray.shortToByteArray(s));
		}
		
		
    void toInfo() throws IOException
    {
        byte[][] infoTemp = new byte[7][0];
        infoTemp[0] = ByteArray.shortToByteArray(max_stack);
        infoTemp[1] = ByteArray.shortToByteArray(max_locals);
        infoTemp[2] = ByteArray.intToByteArray(code_length);
        infoTemp[3] = code;
        infoTemp[4] = ByteArray.shortToByteArray(exception_table_length);
        infoTemp[5] = ByteArray.shortToByteArray(attributes_count);

        if (attributes_count == 0) {}
        else infoTemp[6] = attributes;

        info = ByteArray.flatBytes(infoTemp);
        attribute_length = info.length;
    }
}

// end of Code_attribute.java

