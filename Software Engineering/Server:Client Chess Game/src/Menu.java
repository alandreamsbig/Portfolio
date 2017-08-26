

import javax.swing.JFrame;
import javax.swing.JButton;

import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import java.awt.Color;
import java.awt.event.ActionListener;

import java.awt.event.ActionEvent;

public class Menu 
{
	public GameboardGUI gbgui;

	private JFrame frame;

	/**
	 * Launch the application.
	 */
	public void startGUI() {
//		EventQueue.invokeLater(new Runnable() {
//			public void run() {
				try {
					//Menu window = new Menu();
					this.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
//			}
//		});
	}

	/**
	 * Create the application.
	 */
	public Menu() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.getContentPane().setBackground(new Color(176, 224, 230));
		frame.setBounds(100, 100, 600, 500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JButton btnNewButton = new JButton("Connect to Server");
		btnNewButton.setForeground(new Color(199, 21, 133));
		btnNewButton.setBackground(new Color(255, 255, 255));
		btnNewButton.setBounds(187, 152, 200, 44);
		frame.getContentPane().add(btnNewButton);
		
		JButton btnExit = new JButton("Exit");
		btnExit.setForeground(new Color(199, 21, 133));
		btnExit.setBackground(new Color(255, 255, 255));
		btnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			
				System.exit(0);
			}
		});
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				
				try{
				
					SpaceCheckers.CH.connect();
					String a=SpaceCheckers.CH.ReadPlayer();
				
					if((a!="error")||(a!=null)){
						
					
					SpaceCheckers.playerNo=a;
					SpaceCheckers.execute(a);
					}
					else
					{
						
						JOptionPane.showMessageDialog(null, "Cant connect");
				System.out.println(SpaceCheckers.playerNo);
		
					}
					
					
			
				} catch (Exception ex) {
					JOptionPane.showMessageDialog(null, "Cant connect");
					System.out.println("Could not connect to server. Give it another try.\nerror:\n");
					ex.printStackTrace();
				}

			}
		});
		btnExit.setBounds(225, 230, 117, 29);
		frame.getContentPane().add(btnExit);
		
		JLabel lblSpaceCheckers = new JLabel("SPACE CHECKERS");
		lblSpaceCheckers.setForeground(new Color(139, 0, 139));
		lblSpaceCheckers.setFont(new Font("Nanum Brush Script", Font.PLAIN, 35));
		lblSpaceCheckers.setBounds(140, 57, 300, 67);
		frame.getContentPane().add(lblSpaceCheckers);
		
		JLabel lblVersion = new JLabel("Version 3.0");
		lblVersion.setFont(new Font("Lucida Grande", Font.PLAIN, 10));
		lblVersion.setBounds(260, 318, 61, 16);
		frame.getContentPane().add(lblVersion);
	}

	public void stopGUI() {
		// TODO Auto-generated method stub
		this.frame.setVisible(false);
	}


}
