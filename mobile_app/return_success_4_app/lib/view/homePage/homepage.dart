import 'package:firebase_messaging/firebase_messaging.dart';
import 'package:flutter/material.dart';
import 'package:isar/isar.dart';
import 'package:return_success_4_app/view/homePage/homepage_widgets.dart';

import 'message_history_list.dart';

/// Homepage of the app
class HomePage extends StatefulWidget {
  const HomePage({required this.title, required this.isar, Key? key})
      : super(key: key);

  final String title;
  final Isar isar;

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  /// Sets-up how a click on a notification is handled, from both the Terminated and Background states
  Future<void> setupInteractedMessage() async {
    // Get any messages which caused the application to open from a TERMINATED state.
    RemoteMessage? initialMessage =
        await FirebaseMessaging.instance.getInitialMessage();
    if (initialMessage != null) {
      _handleMessage(initialMessage);
    }
    // Also handle any interaction when the app is in the BACKGROUND via a Stream listener
    FirebaseMessaging.onMessageOpenedApp.listen(_handleMessage);
  }

  /// Function executed when a notification is clicked (currently common for both Terminated and Background states)
  void _handleMessage(RemoteMessage message) {
    //Navigator.pushNamed(context, '/');
  }

  @override
  void initState() {
    super.initState();
    // Setup the handling of interacted messages
    setupInteractedMessage();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SingleChildScrollView(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            // Homepage header
            HomepageHeader(title: widget.title),
            const SizedBox(
              height: 20,
            ),
            // History list of previously received Messages
            MessagesHistoryListView(isar: widget.isar),
          ],
        ),
      ),
    );
  }
}
