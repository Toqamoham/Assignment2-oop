# include "LabelGenerator.h"

int main() {

    LabelGenerator figureNumbers("Figure", 0);

    LabelGenerator pointNumbers("P", 0);

    cout << "Figure Numbers: " << " ";

    for (int i = 0; i < 3; i++) {

        cout << figureNumbers.nextLabel() << " , ";
    }

    cout << '\n' << "Point Numbers: " << " ";

    for (int i = 0; i < 3; i++) {

        cout << pointNumbers.nextLabel() << " , ";
    }

    cout << '\n' << "More Figures: " << " ";

    for (int i = 0; i < 3; i++) {

        cout << figureNumbers.nextLabel() << " , ";
    }

    cout << endl;

    FileLabelGenerator figuresLabels("figure", 0, "toqa.txt");

    cout << "\nFigure labels: \n";

    for (int i = 0; i < 3; i++) {

        cout << figuresLabels.nextLabel() << endl;

    }
    return 0;
}