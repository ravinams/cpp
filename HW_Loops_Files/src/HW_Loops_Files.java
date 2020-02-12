
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author
 */
public class HW_Loops_Files {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        File file = new File("/scratch/WorkExamples/C++/HW_Loops_Files/src/courseData.txt");
        int totalClasses = 0, totalStudents = 0;

        try {

            Scanner sc = new Scanner(file);
            sc.useDelimiter("\n");

            // Global data .
            String globalData = sc.nextLine();
            String globalDataArray[] = globalData.split("\\s+");

            float programsWeight = Float.parseFloat(globalDataArray[0]);
            float midtermWeight = Float.parseFloat(globalDataArray[1]);
            float finalWeight = Float.parseFloat(globalDataArray[2]);

            // Class data & student data 
            double classAverage = 0.0;
            int classCount = 0;
            while (sc.hasNextLine()) {

                if (sc.hasNext()) // this is too avoid exception when the program reaches the last 0
                {

                    String line = sc.nextLine();

                    String lineArray[] = line.split("\\s+");

                    // if the array contains only one word , then either it could be begining of the class i.e classId or end of the class i.e o
                    if (lineArray.length == 1) {
                        int classId = Integer.parseInt(lineArray[0]);

                        if (classId != 0) // class data 
                        {
                            System.out.println("Grade Data For Class " + classId + "\n");
                            System.out.println("ID   Programs   Midterm    Final   Wieghted Average   Programs Grade ");
                            System.out.println(" --  --------   -------    ------  ----------------   --------------- ");

                        } else // 0 ; end of class data , so continue with next class 
                        {
                            System.out.println("Class average " + Math.round(classAverage / classCount * 100.0) / 100.0 + "\n");
                            classAverage = 0.0;
                            classCount = 0;
                            continue;  // process the next class 
                        }
                    } else {  // student data ;

                        int pScore = Integer.parseInt(lineArray[1]);
                        int mScore = Integer.parseInt(lineArray[2]);
                        int fScore = Integer.parseInt(lineArray[3]);
                        double weightedAvergae = Math.round(((pScore * programsWeight) + (mScore * midtermWeight) + (fScore * finalWeight)) * 100.0) / 100.0;
                        String grade = (pScore >= 70 ? "Pass" : "Fail");

                        System.out.println(lineArray[0] + "    " + pScore + "         " + mScore + "         " + fScore + "       " + weightedAvergae + "              " + grade);
                        classAverage = classAverage + weightedAvergae;
                        classCount++;
                    }

                } else {
                    break;
                }
            }

            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}
