import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Label;

import java.util.List;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

public class TextField {

	protected Shell shell;
	private Text word;
	private Label message;
	private Text text;
	private Text text_1;
	private Text text_2;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			TextField window = new TextField();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Open the window.
	 */
	public void open() {
		Display display = Display.getDefault();
		createContents();
		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shell = new Shell();
		shell.setSize(495, 279);
		shell.setText("单词拼写训练");
		shell.setLocation(Display.getCurrent().getClientArea().width/2-shell.getShell().getSize().x/2,
				Display.getCurrent().getClientArea().height/2-shell.getShell().getSize().y/2);
		
		Label label = new Label(shell, SWT.NONE);
		label.setBounds(54, 50, 69, 20);
		label.setText("输入单词：");
		
		word = new Text(shell, SWT.BORDER);
		word.setBounds(129, 47, 218, 33);
		
		Button enter = new Button(shell, SWT.NONE);
		enter.setBounds(350, 42, 98, 42);
		enter.setText("确定");
		
		message = new Label(shell, SWT.NONE);
		message.setBounds(10, 207, 166, 20);
		
		int x = shell.getBounds().width/2;
		int y = shell.getBounds().height/3;
		
		System.out.println("width："+shell.getBounds().width/3+"height："+shell.getBounds().height/3);
		
		enter.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				String str = word.getText();
				String[] words = str.split("");
				int left = x;
				int right = x;
				for(int i = 0; i < words.length; i++) {
					Text text = new Text(shell, SWT.BORDER);
					if(i%2==0) {
						text.setBounds(right, y, 31, 42);
						right += 31;
					}else {
						left -= 31;
						text.setBounds(left, y, 31, 42);
					}
					text.setText(words[i]);
					System.out.println(words[i]);
				}
			}
		});

	}

}
