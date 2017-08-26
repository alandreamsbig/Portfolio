import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class GameboardGUI extends JFrame
{
	static int state=0;
	static Move move=new Move();
	boolean myturn;
	//private Container contents;
	 JFrame frame = new JFrame("Space Checkers");
	
	private JButton[][] squares = new JButton[8][8];
	
	//Get the checker image
	private ImageIcon whitechecker = new ImageIcon(getClass().getResource("whitechecker.png"));
	private ImageIcon redchecker = new ImageIcon(getClass().getResource("redchecker.png"));
	private ImageIcon whiteking = new ImageIcon(getClass().getResource("whiteking.png"));
	private ImageIcon redking= new ImageIcon(getClass().getResource("redking.png"));
	
	  JLabel lblPlayer = new JLabel();
	  JLabel lblWhatEverText = new JLabel();

	public GameboardGUI() throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException
	{
		super ("Space Checkers");
		UIManager.setLookAndFeel( UIManager.getCrossPlatformLookAndFeelClassName() );
		getContentPane().setEnabled(false);
		setResizable(true);
		
	//	contents = getContentPane();
		//contents.setLayout(new GridLayout(8,8));
		JPanel contents=new JPanel();
		contents.setLayout(new GridLayout(8,8));
		 
		
	        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	 
	        //Create the menu bar.  Make it have a green background.
	        
	        
	        JMenuBar  jMenuBar1 = new javax.swing.JMenuBar();
	        
	        lblPlayer.setText("Player: "+SpaceCheckers.playerNo+"        ");
	        lblPlayer.setForeground(new Color(135, 206, 235));
	       
	        lblPlayer.setFont(new Font("Cooper Black", Font.PLAIN, 28));
	        jMenuBar1.add(lblPlayer);
	        
	      
	        lblWhatEverText.setForeground(new Color(135, 206, 235));
	        lblWhatEverText.setFont(new Font("Cooper Black", Font.PLAIN, 28));
	        jMenuBar1.add(lblWhatEverText);

	      
	        jMenuBar1.setBackground(new Color(0, 128, 128));
	        jMenuBar1.setPreferredSize(new Dimension(20, 40));
	 
	        
	       
	        //Create a yellow label to put in the content pane.
	      
	        contents.setSize(700, 700);
	      
	        frame.setPreferredSize(new Dimension(700,700));
	        //Set the menu bar and add the label to the content pane.
	        frame.getContentPane().add(contents, BorderLayout.CENTER);
	        frame.setJMenuBar(jMenuBar1);
	        
	        Component horizontalGlue = Box.createHorizontalGlue();
	        jMenuBar1.add(horizontalGlue);
	        
	        JButton btnNewButton_1 = new JButton("Quit");
	        btnNewButton_1.setForeground(new Color(173, 216, 230));
	        btnNewButton_1.setBackground(new Color(34, 139, 34));
	        btnNewButton_1.setFont(new Font("Cooper Black", Font.PLAIN, 28));
	        jMenuBar1.add(btnNewButton_1);
	        
	        JButton btnNewButton = new JButton("Help");
	        btnNewButton.setForeground(new Color(173, 216, 230));
	        btnNewButton.setBackground(new Color(34, 139, 34));
	        btnNewButton_1.addActionListener(new ActionListener(){
	        	public void actionPerformed(ActionEvent e) {
	        		SpaceCheckers.gbgui.frame.setVisible(false);
	        		SpaceCheckers.mn.startGUI();;
	        		SpaceCheckers.CH.closeConnection();
	        		
	        }
	        });
	        btnNewButton.addActionListener(new ActionListener() {
	        	public void actionPerformed(ActionEvent e) {
	        		JOptionPane.showMessageDialog(null, "1. Checkers is played by two players. Each player begins the game with 12 colored discs. \n2. The board consists of 64 squares, alternating between 32 dark and 32 light squares."
	        				+ "\n		It is positioned so that each player has a light square on the right side"
	        				+ "\n		corner closest to him or her. Each player places his or her pieces on the 12 dark squares closest to him or her."
	        				+ "\n3. Player 1 moves first. Players then alternate moves." + "\n		Moves are allowed only on the dark squares, so pieces always move diagonally."
	        				+ "\n		Single pieces are always limited to forward moves (toward the opponent)."
	        				+ "A piece making a non-capturing move (not involving a jump) may move only one square."
	        				+ "\n4. A piece making a capturing move (a jump) leaps over one of the opponent's pieces, landing in a straight diagonal line on the other side." 
	        				+ "\n		Only one piece may be captured in a single jump;" 
	        				+ "\n 	however, multiple jumps are allowed during a single turn. When a piece is captured, it is removed from the board."
	        				+ "\n5.	If a player is able to make a capture, \n		there is no option -- the jump must be made. If more than one capture is" 
	        				+ "\n		available, the player is free to choose whichever he or she prefers."
	        				+ "\n6. When a piece reaches the furthest row from the player who controls that piece, it is crowned and becomes a king. "
	        				+ "\n			One of the pieces which had been captured is placed on top of the king" 
	        				+ "\n 		so that it is twice as high as a single piece."
	        				+ "\n7. Kings are limited to moving diagonally, but may move both forward and backward."
	        				+ "\n			(Remember that single pieces, i.e. non-kings, are always limited to forward moves.)"
	        				+ "\n8. Kings may combine jumps in several directions -- forward and backward -- on the same turn. Single pieces may shift"
	        				+ "\n			direction diagonally during a multiple capture turn, but must always jump forward (toward the opponent)."
	        				+ "\n9. A player wins the game when the opponent cannot make a move. In most cases, this is because all of the opponent's pieces "
	        				+ "\n			have been captured, but it could also be because all of his pieces are blocked in.");
      		
	        	}
	        });
	        btnNewButton.setFont(new Font("Cooper Black", Font.PLAIN, 28));
	        jMenuBar1.add(btnNewButton);
	      
	       
	 
	        //Display the window.
	        frame.pack();
	        frame.setVisible(true);
		
		ButtonHandler buttonHandler = new ButtonHandler();
		
		//Create the 8x8 checkerboard grid with buttons
		for (int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				squares[i][j] = new JButton();
				if((i + j) % 2 != 0)
				{
					squares[i][j].setBackground(Color.decode("0x649E5B"));	
				} else {
					squares[i][j].setBackground(Color.decode("0xC3C667"));	
				}
				contents.add(squares[i][j]);
				squares[i][j].setOpaque(true);
				squares[i][j].addActionListener(buttonHandler);
			}
				
		}
		//Set grid to checker image
//		squares[row][col].setIcon(checkers);
		
	
		

		setSize(600,600);

		setSize(800,800);

		setLocationRelativeTo(null);
		//setVisible(true);
	}
	

	
	//Check for mouse click
	private void processClick(int i, int j)
	{
	
	//	SpaceCheckers.RC.findValidMoves(piece, gameBoard)
		if(state==0) {
  			move.setStartRow(i);
  			move.setStartCol(j);
			
			if (!SpaceCheckers.gameBoard.getPieces()[i][j].alive)
				return;		// return if a not-alive piece was clicked
			
			state=state+1;
		}
		else if(state==1)
		{
			move.setDestRow(i);
			move.setDestCol(j);
			
			String isValid = SpaceCheckers.ruleChecker.isValidMove(move, SpaceCheckers.gameBoard);
			if(isValid.equals("valid"))
			{
				SpaceCheckers.CH.Write(move);
				Move smove=SpaceCheckers.CH.Read();
				
				myturn=smove.myturn;
				if(!myturn)
					lblWhatEverText.setText("Opponents Turn");
				
			
				SpaceCheckers.gameBoard.makeMove(smove);
				
				SpaceCheckers.gbgui.setUpPieces(SpaceCheckers.gameBoard);
				
				if(SpaceCheckers.ruleChecker.gameOver(SpaceCheckers.gameBoard))
				{
					JOptionPane.showMessageDialog(null, "YOU WON!");
					SpaceCheckers.gbgui.frame.setVisible(false);
					SpaceCheckers.mn.startGUI();
					SpaceCheckers.CH.closeConnection();
				}
			}
			else
			{
				if (isValid.equals("mustJump"))
					JOptionPane.showMessageDialog(null, "You must jump!");
				else
					JOptionPane.showMessageDialog(null, "Invalid Move!");
			}
				
					state=0;
			/*	if(!myturn)
					{
						GameboardGUI.ButtonHandler nb=this.new ButtonHandler();

						 nb.actionPerformed(new ActionEvent(new Object(), ActionEvent.ACTION_PERFORMED, null));
					}   */
		}
	}
	
	
	public void setUpPieces(GameBoard gb) {
		Piece[][] p = gb.pieces;
		for (int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if (p[i][j].alive) {
					if (p[i][j].color.equals("red")) {
							if(p[i][j].king)
								squares[i][j].setIcon(redking);
							else
								squares[i][j].setIcon(redchecker);
					} else if (p[i][j].color.equals("white")) {
							if(p[i][j].king)
								squares[i][j].setIcon(whiteking);
							else
								squares[i][j].setIcon(whitechecker);
					}
				}
				else 
				{
					squares[i][j].setIcon(null);
				}
				
				
			}
		}
	}
	
	// Move checker piece to where the mouse click
	protected class ButtonHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			if(myturn==true) {
				lblWhatEverText.setText("Your Turn");
				Object source = e.getSource();
			
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if(source == squares[i][j])
						{
							processClick(i,j);
							return;
						}
					}
				}
			}
			else {
			//	JOptionPane.showMessageDialog(null, "Opponent's turn");
				lblWhatEverText.setText("Opponents Turn");
				 
				Move mv=SpaceCheckers.CH.Read();
				myturn=mv.myturn;
				if(myturn)
					lblWhatEverText.setText("your Turn");
				
				mv.reverse();
				SpaceCheckers.gameBoard.makeMove(mv);

				SpaceCheckers.gbgui.setUpPieces(SpaceCheckers.gameBoard);
				
				if(SpaceCheckers.ruleChecker.gameOver(SpaceCheckers.gameBoard))
				{
					JOptionPane.showMessageDialog(null, "SORRY, YOU LOST...");
					SpaceCheckers.gbgui.frame.setVisible(false);
					SpaceCheckers.CH.closeConnection();
					SpaceCheckers.mn.startGUI();
				}
			}
		}

	}
	
}