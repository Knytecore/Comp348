
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import java.io.IOException;

import java.util.ArrayList;
import java.util.Collections;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Shape[] shapes;
		Scanner sc = null; // Create Scanner object
		Scanner kb = new Scanner(System.in);
		boolean loop = false;
		do {
			System.out.println();
			System.out.println("Please enter file name"); // Prompt User input
			String s1 = kb.next();

			try {
				sc = new Scanner(new FileInputStream(s1));
				shapes = new Shape[displayFileContents(sc).size()]; // using method to display HTML contents

				loop = true;

			} catch (FileNotFoundException e) {

				System.out.println("Could not open input file " + s1 + " for reading." + "\n"
						+ "Please check that the file exists and is readable. This program will terminate after closing any opened files.");

				System.out.println(e.getMessage());
				System.exit(0);

			} catch (IOException e) {
				System.out.println("Could not open input file " + s1 + "for reading."
						+ "Please check that the file exists and is readable. This program will terminate after closing any opened files.");
				System.out.println(e.getMessage());
				System.exit(0);
			}

		} while (!loop);

	}

	public static ArrayList<Shape> displayFileContents(Scanner sc) throws FileNotFoundException, IOException {
		String line[];
		ArrayList<Shape> list = new ArrayList<Shape>();
		while (sc.hasNextLine()) {

			line = sc.nextLine().split(",");
			if (line[0].equals("Rectangle")) {
				Rectangle r = new Rectangle();
				r = Rectangle.parse(line);
				list.add(r);
			} else if (line[0].equals("Circle")) {
				Circle c = new Circle();
				c = Circle.parse(line);
				list.add(c);
			}

		}
		
		
		
		// Display original list in txt file
		System.out.println("\nDisplaying unsorted Shapes in txt file:");
		
		for (Shape shape : list) {
			Printable.print(shape);
		}

		// Sorting using comparator
		
		// Sorting by area (from smallest to biggest)
		System.out.println("\n\nSorting by Area:");
		Collections.sort(list, Shape.areaComparator);
		
		for (Shape shape : list) {
			Printable.print(shape);
		}
		
		// Sorting by shape name (Circles together, rectangles together)
		System.out.println("\n\nSorting previsouly sorted list by Shape:");
		
		Collections.sort(list, Shape.nameComparator);

		for (Shape shape : list) {
			Printable.print(shape);
		}
		sc.close(); // Must close the file

		return list;
	}

}
