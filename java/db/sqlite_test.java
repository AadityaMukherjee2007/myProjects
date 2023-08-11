import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class sqlite_test
{
	public static void connect()
	{
		Connection con = null;
		try
		{
			String url = "jdbc:sqlite:info.db";
			con = DriverManager.getConnection(url);

			System.out.println("Connection established!");
		}
		catch (SQLException e)
		{
			System.out.println(e.getMessage());
		}
	}

	public static void main(String args[])
	{
		connect();
	}
}