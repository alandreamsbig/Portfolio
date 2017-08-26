import javax.swing.JPanel;
import javax.swing.JTextPane;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JTextArea;
import java.awt.Color;
import javax.swing.JLabel;
import java.awt.Font;

public class GamePopUp extends JPanel {

	/**
	 * Create the panel.
	 */
	public GamePopUp() {
		setBackground(new Color(216, 191, 216));
		setLayout(null);
		
		JButton btnQuit = new JButton("Quit");
		btnQuit.setForeground(new Color(199, 21, 133));
		btnQuit.setBounds(21, 17, 117, 29);
		add(btnQuit);
		
		JLabel lblCheckerRules = new JLabel("Checker Rules");
		lblCheckerRules.setBounds(31, 58, 107, 16);
		add(lblCheckerRules);
		
		JTextArea txtrCheckersIsPlayed = new JTextArea();
		txtrCheckersIsPlayed.setFont(new Font("Lucida Grande", Font.PLAIN, 10));
		txtrCheckersIsPlayed.setText("Checkers is played by two players. Each player begins the game with 12 colored discs. (Typically, one set of pieces is black and the other red.)\nThe board consists of 64 squares, alternating between 32 dark and 32 light squares. It is positioned so that each player has a light square on the right side corner closest to him or her.\nEach player places his or her pieces on the 12 dark squares closest to him or her.\nBlack moves first. Players then alternate moves.\nMoves are allowed only on the dark squares, so pieces always move diagonally. Single pieces are always limited to forward moves (toward the opponent).\nA piece making a non-capturing move (not involving a jump) may move only one square.\nA piece making a capturing move (a jump) leaps over one of the opponent's pieces, landing in a straight diagonal line on the other side. Only one piece may be captured in a single jump; however, multiple jumps are allowed during a single turn.\nWhen a piece is captured, it is removed from the board.\nIf a player is able to make a capture, there is no option -- the jump must be made. If more than one capture is available, the player is free to choose whichever he or she prefers.\nWhen a piece reaches the furthest row from the player who controls that piece, it is crowned and becomes a king. One of the pieces which had been captured is placed on top of the king so that it is twice as high as a single piece.\nKings are limited to moving diagonally, but may move both forward and backward. (Remember that single pieces, i.e. non-kings, are always limited to forward moves.)\nKings may combine jumps in several directions -- forward and backward -- on the same turn. Single pieces may shift direction diagonally during a multiple capture turn, but must always jump forward (toward the opponent).\nA player wins the game when the opponent cannot make a move. In most cases, this is because all of the opponent's pieces have been captured, but it could also be because all of his pieces are blocked in.");
		txtrCheckersIsPlayed.setBounds(6, 86, 438, 208);
		add(txtrCheckersIsPlayed);

	}
}
