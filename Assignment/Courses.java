package Assignment;

public class Courses {
    String Title;
    String code;
    String Faculty;
    int Credits;
    String timings;

    Courses(String Title, String code, String Faculty, int Credits, String timings) {
        this.Title = Title;
        this.code = code;
        this.Faculty = Faculty;
        this.Credits = Credits;
        this.timings = timings;
    }

    @Override

    public String toString() {
        return String.format("| %-10s | %-8s | %-12s | %-8d | %-18s |\n",
                Title, code, Faculty, Credits, timings);
    }

    @Override
    public int hashCode() {
        // converting all datatypes to string
        String strTitle = String.valueOf(Title);
        String strCode = String.valueOf(code);
        String strFaculty = String.valueOf(Faculty);
        String strCredits = String.valueOf(Credits);
        String strtimings = String.valueOf(timings);

        int hashTitle = strTitle.hashCode();
        int hashcode = strCode.hashCode();
        int hashFaculty = strFaculty.hashCode();
        int hashCredits = strCredits.hashCode();
        int hashtimings = strtimings.hashCode();

        return hashTitle + hashcode + hashFaculty + hashCredits + hashtimings;
    }
}
