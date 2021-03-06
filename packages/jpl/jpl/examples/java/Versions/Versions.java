import java.util.Hashtable;
import jpl.*;

public class Versions
{
	public static void
	main( String argv[] )
	{

		Compound goal1 = 
		    new Compound("consult",
				 new Term[] { 
				     new Compound("library",
						  new Term[] {
						      new Atom("jpl") }
						  )
				 });
		Query q1 = new Query(goal1);
		if ( !q1.hasSolution() ) {
		    System.out.println( "consult(library(jpl)) failed" );
		    return;
		}
		String prologVersion = ((Term) (new Query("jpl_pl_lib_version(V)")).oneSolution().get("V")).name();
		String javaVersion = jpl.JPL.version_string();
		String cVersion = jpl.fli.Prolog.get_c_lib_version();

		System.out.println( "prolog library version; " + prologVersion );
		System.out.println( "  java library version; " + javaVersion );
		System.out.println( "     c library version; " + cVersion );

		if ( prologVersion.equals(javaVersion) && javaVersion.equals(cVersion) ) {
			System.out.println( "BINGO! you appear to have the same version of each library installed");
		} else {
			System.out.println( "WHOOPS! you appear not to have the same version of each library installed");
		}

	}

}


