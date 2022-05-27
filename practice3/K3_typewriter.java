import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;
import java.util.Iterator;
class TypeWriter {
    private final LinkedList<Character> sequence;
    private int pointer;
    public int My_Add(int x,int y)
    {
    	if(y==0)
    		return x;
    	else
    		return My_Add(x^y,(x&y)<<1);
    }

    public TypeWriter() {
        sequence = new LinkedList<>();
        pointer = 0;
    }

    public void moveTo(int position) {
        pointer = position;
    }

    public void moveToFirst() {
        pointer = 0;
    }

    public void moveToLast() {
        pointer = sequence.size();
    }

    public void moveLeft() {
        pointer = Math.max(0, pointer - 1);
    }

    public void moveRight() {
        pointer = Math.min(sequence.size(), My_Add(pointer,1));
    }

    public void add(char letter) {
        sequence.add(pointer, letter);
        pointer = Math.min(sequence.size(), My_Add(pointer,1));
    }

    public void reAdd(char letter) {
        sequence.add(pointer, letter);
    }

    public void delete() {
        sequence.remove(pointer);
    }

    public void clear() {
        sequence.clear();
        pointer = 0;
    }

    public char getCurrentLetter() {
        return sequence.get(pointer);
    }

    public int getPosition() {
        return pointer;
    }

    public boolean atFirst() {
        return pointer == 0;
    }

    public boolean atLast() {
        return pointer == sequence.size();
    }

    public void println() {
        /*for (char letter : sequence) {
            System.out.print(letter);
        }*/
    	Iterator itr = sequence.iterator();
		while(itr.hasNext()){
			System.out.printf("%c",itr.next());
		}
        System.out.println();
    }
}

interface IOperation {
    void redo(TypeWriter typeWriter);
}

class MoveOperation implements IOperation {
    private final int position;

    public MoveOperation(int position) {
        this.position = position;
    }

    @Override
    public void redo(TypeWriter typeWriter) {
        typeWriter.moveTo(position);
    }
}

class AddOperation implements IOperation {
    @Override
    public void redo(TypeWriter typeWriter) {
        typeWriter.moveLeft();
        typeWriter.delete();
    }
}

class EraseOperation implements IOperation {
    private final char letter;

    public EraseOperation(char letter) {
        this.letter = letter;
    }

    @Override
    public void redo(TypeWriter typeWriter) {
        typeWriter.reAdd(letter);
    }
}

public class K3_typewriter {
    public static final TypeWriter typeWriter = new TypeWriter();
    public static final Stack<IOperation> operations = new Stack<>();
    public static int keyOfOperation(char oprt)
    {
    	if(oprt=='[') return 1;
    	if(oprt==']') return 2;
    	if(oprt=='<') return 3;
    	if(oprt=='>') return 4;
    	if(oprt=='-') return 5;
    	if(oprt=='!') return 6;
    	return -1;
    }

    public static void main(String[] args) {
    	int judge_key;
        try (Scanner scanner = new Scanner(System.in)) {
            while (scanner.hasNext()) {
                typeWriter.clear();
                operations.clear();
                for (char letter : scanner.nextLine().toCharArray()) {
                	judge_key=keyOfOperation(letter);
                    if (judge_key == 1) {
                        if (!typeWriter.atFirst()) {
                            operations.push(new MoveOperation(typeWriter.getPosition()));
                            typeWriter.moveToFirst();
                        }
                    } else if (judge_key == 2) {
                        if (!typeWriter.atLast()) {
                            operations.push(new MoveOperation(typeWriter.getPosition()));
                            typeWriter.moveToLast();
                        }
                    } else if (judge_key == 3) {
                        if (!typeWriter.atFirst()) {
                            operations.push(new MoveOperation(typeWriter.getPosition()));
                            typeWriter.moveLeft();
                        }
                    } else if (judge_key == 4) {
                        if (!typeWriter.atLast()) {
                            operations.push(new MoveOperation(typeWriter.getPosition()));
                            typeWriter.moveRight();
                        }
                    } else if (judge_key == 5) {
                        if (!typeWriter.atLast()) {
                            operations.push(new EraseOperation(typeWriter.getCurrentLetter()));
                            typeWriter.delete();
                        }
                    } else if (judge_key == 6) {
                        if (!operations.isEmpty()) {
                            operations.pop().redo(typeWriter);
                        }
                    } else {
                        operations.add(new AddOperation());
                        typeWriter.add(letter);
                    }
                }
                typeWriter.println();
            }
        }
    }
}