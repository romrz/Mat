
public class JNIWorkspace
{
    public static long workspacePointer;
    
    public static native long initWorkspace();
    public static native void deleteWorkspace(long workspacePointer);
    
    public static native void newMatrix(long workspacePointer, String matrix);
    public static native String findMatrix(long workspacePointer, String name);
    public static native void updateMatrix(long workspacePointer, String matrix);
    public static native void deleteMatrix(long workspacePointer,String name);
    
    public static native String resolveExpression(long workspacePointer, String expression);

    static { System.loadLibrary("JNIWorkspace"); }
    
    public static void main(String args[])
    {
	workspacePointer = initWorkspace();

	String m1 = "A 2 2 1 2 3 4";
	String rm1 = findMatrix(workspacePointer, "A");

	System.out.println(rm1);

	deleteWorkspace(workspacePointer);
    }
}
