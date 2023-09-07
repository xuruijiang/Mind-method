import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Button;

import java.util.Random;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MenuItem;
import org.eclipse.swt.events.MouseAdapter;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

public class MainClass {

	protected Shell shell;
	private Text number1;
	private Text number2;
	private Text result;
	private int min, max;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			MainClass window = new MainClass();
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
		shell.setSize(643, 204);
		shell.setText("��������");
		shell.setLocation(Display.getCurrent().getClientArea().width/2-shell.getShell().getSize().x/2,
				Display.getCurrent().getClientArea().height/2-shell.getShell().getSize().y/2);
		
		Button get = new Button(shell, SWT.NONE);
		get.setBounds(23, 60, 98, 30);
		get.setText("\u83B7\u53D6\u9898\u76EE");
		
		number1 = new Text(shell, SWT.BORDER | SWT.READ_ONLY);
		number1.setBounds(127, 62, 73, 26);
		
		number2 = new Text(shell, SWT.BORDER | SWT.READ_ONLY);
		number2.setBounds(237, 62, 73, 26);
		
		Label lblNewLabel = new Label(shell, SWT.NONE);
		lblNewLabel.setBounds(208, 63, 21, 20);
		lblNewLabel.setText("\u2795");
		
		Label lblNewLabel_1 = new Label(shell, SWT.NONE);
		lblNewLabel_1.setBounds(316, 63, 21, 20);
		lblNewLabel_1.setText("\uFF1D");
		
		result = new Text(shell, SWT.BORDER);
		result.setBounds(339, 62, 73, 26);
		
		Button enter = new Button(shell, SWT.NONE);
		enter.setBounds(418, 60, 98, 30);
		enter.setText("\u786E\u8BA4\u7B54\u6848");
		
		Label message = new Label(shell, SWT.NONE);
		message.setBounds(522, 65, 89, 20);
		
		Menu menu = new Menu(shell, SWT.BAR);
		shell.setMenuBar(menu);
		
		MenuItem mntmNewSubmenu = new MenuItem(menu, SWT.CASCADE);
		mntmNewSubmenu.setText("\u9009\u62E9\u7EA7\u522B");
		
		Menu menu_1 = new Menu(mntmNewSubmenu);
		mntmNewSubmenu.setMenu(menu_1);
		
		MenuItem menuItem = new MenuItem(menu_1, SWT.NONE);
		menuItem.setText("\u7B80\u5355");
		
		MenuItem menuItem_1 = new MenuItem(menu_1, SWT.NONE);
		menuItem_1.setText("\u4E00\u822C");
		
		MenuItem menuItem_2 = new MenuItem(menu_1, SWT.NONE);
		menuItem_2.setText("\u56F0\u96BE");
		
		Random r = new Random();
		
		menuItem.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				min = 0;
				max = 11;
			}
		});
		
		menuItem_1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				min = 10;
				max = 91;
			}
		});
		
		menuItem_2.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				min = 100;
				max = 901;
			}
		});
		
		get.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				result.setText("");
				message.setText("");
				int num1 = r.nextInt(max) + min;
				int num2 = r.nextInt(max) + min;
				number1.setText(num1+"");
				number2.setText(num2+"");
			}
		});
		
		enter.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				int total = Integer.parseInt(number1.getText()) + Integer.parseInt(number2.getText());
				if(total == Integer.parseInt(result.getText())) {
					message.setText("��ش���ȷ");
				} else {
					message.setText("��ش����");
				}
			}
		});

	}
}
