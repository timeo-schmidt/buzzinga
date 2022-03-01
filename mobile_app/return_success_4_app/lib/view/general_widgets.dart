import 'package:flutter/material.dart';

/// Custom transparent AppBar used in Scaffolds throughout the app
AppBar transparentAppBar() {
  return AppBar(
    elevation: 0,
    backgroundColor: Colors.transparent,
    iconTheme: const IconThemeData(
      color: Colors.black,
      size: 26,
    ),
  );
}

/// Colourful circular button with an icon
Widget iconButton(
    {double size = 45,
    String? label,
    labelWeight = FontWeight.w500,
    double iconRatio = 2.0 / 3.0,
    required IconData icon,
    required Color color,
    required Function onPressed}) {
  return GestureDetector(
    onTap: () {
      onPressed();
    },
    child: Row(
      crossAxisAlignment: CrossAxisAlignment.center,
      children: [
        // Icon
        Container(
            height: size,
            width: size,
            decoration: BoxDecoration(
              color: color,
              borderRadius: const BorderRadius.all(Radius.circular(50)),
            ),
            child: Icon(
              icon,
              size: (size * iconRatio),
              color: Colors.white,
            )),
        // Label (if any)
        (label == null)
            ? Container(
                width: 0,
              )
            : Padding(
                padding: const EdgeInsets.only(left: 16),
                child: Text(
                  label,
                  style: TextStyle(
                    fontSize: (size * 20 / 45),
                    fontWeight: labelWeight,
                  ),
                ),
              ),
      ],
    ),
  );
}

/// A customizable pop-up alert dialog
Widget buildPopupDialog(
    {required BuildContext context,
    required String dialogTitle,
    required List<Widget> dialogContent,
    required String buttonText,
    required Function onButtonPressed}) {
  return AlertDialog(
    shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
    contentPadding: const EdgeInsets.fromLTRB(24, 20, 24, 10),
    title: Text(dialogTitle),
    content: Column(
      mainAxisSize: MainAxisSize.min,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: dialogContent,
    ),
    actions: [
      TextButton(
        child: const Text("Cancel"),
        onPressed: () {
          Navigator.of(context).pop();
        },
      ),
      TextButton(
        child: Text(buttonText),
        onPressed: () {
          onButtonPressed();
          Navigator.of(context).pop();
        },
      ),
    ],
  );
}
