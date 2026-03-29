package Assignment;

public class Courses {
    String Title;
    String code;
    String Faculty;
    int Credits;

    Courses(String Title, String code, String Faculty, int Credits) {
        this.Title = Title;
        this.code = code;
        this.Faculty = Faculty;
        this.Credits = Credits;
    }

    @Override
    public String toString() {

        return Title + "\t|\t" + code + "\t|\t" + Faculty + "\t|\t" + Credits + "\n";
    }

    @Override
    public int hashCode() {
        // converting all datatypes to string
        String strTitle = String.valueOf(Title);
        String strCode = String.valueOf(code);
        String strFaculty = String.valueOf(Faculty);
        String strCredits = String.valueOf(Credits);

        int hashTitle = strTitle.hashCode();
        int hashcode = strCode.hashCode();
        int hashFaculty = strFaculty.hashCode();
        int hashCredits = strCredits.hashCode();

        return hashTitle + hashcode + hashFaculty + hashCredits;
    }
}
