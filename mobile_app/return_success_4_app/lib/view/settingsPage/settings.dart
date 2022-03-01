import 'package:flutter/material.dart';
import 'package:isar/isar.dart';
import 'package:return_success_4_app/controller/message_database_service.dart';

import '../general_widgets.dart';

/// Settings page of the app
class SettingsPage extends StatelessWidget {
  const SettingsPage({required this.isar, Key? key}) : super(key: key);

  final Isar isar;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: transparentAppBar(),
      body: Padding(
        padding: const EdgeInsets.all(32.0),
        child: Column(
          children: [
            const SizedBox(height: 16),
            iconButton(
                label: "Information",
                icon: Icons.info_outline_rounded,
                color: const Color.fromARGB(255, 223, 193, 26),
                onPressed: () {
                  Navigator.pushNamed(
                    context,
                    "/info",
                  );
                }),
            const SizedBox(height: 24),
            iconButton(
                label: "Manage my devices",
                icon: Icons.mode_edit_rounded,
                iconRatio: 0.6,
                color: const Color.fromARGB(255, 35, 108, 202),
                onPressed: () {
                  Navigator.pushNamed(
                    context,
                    "/edit",
                  );
                }),
            const SizedBox(height: 24),
            iconButton(
              label: "Clear stored messages",
              icon: Icons.delete_forever_rounded,
              color: const Color.fromARGB(255, 173, 35, 35),
              onPressed: () {
                showDialog(
                  context: context,
                  builder: (BuildContext context) => buildPopupDialog(
                      context: context,
                      dialogTitle: "Warning",
                      dialogContent: [
                        const Text(
                          'Are you sure you want to delete all stored messages?',
                        )
                      ],
                      buttonText: "Clear all",
                      onButtonPressed: () async {
                        await MessageDatabaseService().clearMessagesDB(isar);
                        Navigator.pop(context);
                      }),
                );
              },
            ),
          ],
        ),
      ),
    );
  }
}
