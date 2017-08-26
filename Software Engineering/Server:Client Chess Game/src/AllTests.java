import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({ TestClass.class ,PieceTest.class,GameBoardTests.class,RuleCheckerTests.class})
public class AllTests {

}
