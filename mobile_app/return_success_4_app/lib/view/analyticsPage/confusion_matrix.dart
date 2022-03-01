import 'package:flutter/material.dart';

/// A card that displays a confusion matrix (a table)
// TODO: Fill-in the Confusion Matrix in the anlytics page
Widget confusionMatrixCard() {
  return Container(
    margin: const EdgeInsets.fromLTRB(8, 8, 8, 0),
    padding: const EdgeInsets.fromLTRB(6, 10, 6, 10),
    decoration: const BoxDecoration(
      color: Colors.white,
      borderRadius: BorderRadius.all(Radius.circular(20)),
      boxShadow: [
        BoxShadow(
          color: Color.fromARGB(25, 0, 0, 0),
          offset: Offset(0, 2),
          blurRadius: 8,
        ),
      ],
    ),
    child: Table(
      border: null,
      children: [
        // 1st row
        TableRow(children: [
          cell(text: ""),
          cell(text: "Doorbell", weight: FontWeight.bold),
          cell(text: "Fire Alarm", weight: FontWeight.bold),
          cell(text: "Noise", weight: FontWeight.bold),
        ]),

        // 2nd row
        TableRow(children: [
          cell(text: "Doorbell", weight: FontWeight.bold),
          cell(text: "92%"),
          cell(text: "5%", color: Colors.grey),
          cell(text: "3%", color: Colors.grey),
        ]),

        // 3rd row
        TableRow(children: [
          cell(text: "Fire Alarm", weight: FontWeight.bold),
          cell(text: "8%", color: Colors.grey),
          cell(text: "88%"),
          cell(text: "4%", color: Colors.grey),
        ]),

        // 4th row
        TableRow(children: [
          cell(text: "Noise", weight: FontWeight.bold),
          cell(text: "0%", color: Colors.grey),
          cell(text: "7%", color: Colors.grey),
          cell(text: "93%"),
        ]),
      ],
    ),
  );
}

/// Customizable cell type used for displaying text in tables
Widget cell({
  required String text,
  FontWeight weight = FontWeight.w500,
  Color color = Colors.black,
}) {
  return Padding(
    padding: const EdgeInsets.only(top: 12.0, bottom: 12.0),
    child: Text(
      text,
      textAlign: TextAlign.center,
      style: TextStyle(fontWeight: weight, color: color),
    ),
  );
}
