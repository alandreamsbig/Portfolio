import javax.swing.UnsupportedLookAndFeelException;


public class SpaceCheckers {
	
	static GameBoard gameBoard = new GameBoard();
	static RuleChecker ruleChecker = new RuleChecker();
	static String playerNo = null;
	static ConnectionHelper CH=	new ConnectionHelper();
	static GameboardGUI gbgui =null;
	static 	Menu mn = new Menu();
	
	public static void execute(String p) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException{
		System.out.println(playerNo);
		gameBoard.initialize(playerNo);
		
		gbgui = new GameboardGUI();
		gbgui.myturn = playerNo.equals("1") ? true : false;
		gbgui.setUpPieces(gameBoard);
		 
		 
		 //issue and we need to implement
		// if(playerNo.equals("2")){
		//	 GameboardGUI.ButtonHandler nb=gbgui.new ButtonHandler();
		//	 nb.actionPerformed(new ActionEvent(new Object(), ActionEvent.ACTION_PERFORMED, null));
		//}
		 
		 mn.stopGUI();
		 //gbgui.setVisible(true);
	}
	
	public static void main(String args[]) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException
	{
		// check what the playerNo is sent by server in startGUI() and set the global var to it
		mn.startGUI();
	}

}
