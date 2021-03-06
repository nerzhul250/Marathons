import java.util.NoSuchElementException;

class Node{
	String palabra;
	Node parent,left,right;
	public Node(Node p,Node l, Node r,String pa) {
		parent=p;
		left=l;
		right=r;
		palabra=pa;
	}
}
class TreeIterator {
    private Node next;

    public TreeIterator(Node root) {
        next = root;
        if(next == null)
            return;
        do {
        	if(next!=root)next=next.right;
        	while (next.left != null)
                next = next.left;
        }while(next.right!=null);
    }

    public boolean hasNext(){
        return next != null;
    }

    public Node next(){
        if(!hasNext()) throw new NoSuchElementException();
        Node r = next;
        if(next.parent==null) {next=null;return r;}
        if(next==next.parent.left) {
        	next=next.parent;
        	if(next.right!=null) {
        		do {
                	next=next.right;
                	while (next.left != null)
                        next = next.left;
                }while(next.right!=null);
        	}
        	return r;
        }else{
        	next=next.parent;
        	return r;
        }
        
     }
 }
public class PostOrdenIterator {

	public static void main(String[] args) {
		Node n1=new Node(null,null,null,"");
		Node n2=new Node(null,null,null,"");
		Node n3=new Node(null,null,null,"");
		Node n4=new Node(null,null,null,"");
		Node n5=new Node(null,null,null,"");
		Node n6=new Node(null,null,null,"");
		n1.left=n2;n2.parent=n1;n1.right=n3;n3.parent=n1;
		n2.left=n4;n4.parent=n2;
		n3.left=n5;n3.right=n6;n5.parent=n3;n6.parent=n3;
		n1.palabra="1";
		n2.palabra="2";
		n3.palabra="3";
		n4.palabra="Go";
		n5.palabra="og";
		n6.palabra="le!";
		TreeIterator ti=new TreeIterator(n1);
		while(ti.hasNext()) {
			System.out.println(ti.next().palabra);
		}
	}

}
