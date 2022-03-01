import 'package:flutter/gestures.dart';
import 'package:flutter/material.dart';
import 'package:url_launcher/url_launcher.dart';

import '../general_widgets.dart';

/// A page that displays text information about the app
class InfoPage extends StatelessWidget {
  const InfoPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: transparentAppBar(),
      body: SingleChildScrollView(
        child: Padding(
          padding: const EdgeInsets.all(12.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.start,
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              const Text("What is this app?",
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
              const SizedBox(
                height: 8,
              ),
              const Text(
                  "This app is to be used in conjunction with a compatible device. Once you have set-up your device and added it to the app, you will receive notifications for specific sound events happening in your home."),
              const SizedBox(
                height: 8,
              ),
              const Text(
                  "For example, you could put your device next to your interphone and receive notifications on your phone whenever your doorbell rings. This can also be used for a growing list of other sound events, such as fire alarms going off."),
              const SizedBox(
                height: 24,
              ),
              const Text("What/who is it for?",
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
              const SizedBox(
                height: 8,
              ),
              const Text(
                  "The app can be used by anyone, with an emphasis on people with hearing difficulties. This allows them to receive visual cues of sound events happening around them and in their home."),
              const SizedBox(
                height: 8,
              ),
              const Text(
                  "This can of course also be used more generally as a relay for all these sound events, for example to alert you that someone is at your door when you are in a remote room and can't hear the doorbell, or to alert you of a potential fire when you are away from home."),
              const SizedBox(
                height: 24,
              ),
              const Text("How to use it?",
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
              const SizedBox(
                height: 8,
              ),
              const Text(
                  'Add your devices in the "Manage my devices" section, providing both your unique device ID (found on your device or in the documentation) and choosing the detection mode that you want your device to operate on.'),
              const SizedBox(
                height: 8,
              ),
              const Text(
                  "For more detailed use-cases of your device, please refer to the official documentation."),
              const SizedBox(
                height: 24,
              ),
              const Text("Credits",
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
              const SizedBox(
                height: 8,
              ),
              const Text(
                  "This app was developped as part of the first coursework for Embedded Systems 21/22 (EIE MEng @ Imperial College London) of the group returnSuccess4."),
              const SizedBox(
                height: 8,
              ),
              const Text(
                  "The app was programmed in Dart using the Flutter framework. It was developped and debugged using both a Pixel 5 and a Pixel 4 running Android 12 (virtual devices), and was tested using a Galaxy S8 running Android 9 (real device)."),
              const SizedBox(
                height: 8,
              ),
              Text.rich(TextSpan(children: [
                const TextSpan(
                    text:
                        "Please report all bugs or feature requests to the GitHub page of the project: "),
                TextSpan(
                    style: const TextStyle(
                        color: Colors.blue,
                        decoration: TextDecoration.underline),
                    //make link blue and underline
                    text: "GitHub repository",
                    recognizer: TapGestureRecognizer()
                      ..onTap = () async {
                        String url =
                            "https://github.com/tlp19/return_success_4_app";
                        var urllaunchable = await canLaunch(url);
                        if (urllaunchable) {
                          await launch(url);
                        }
                      }),
              ]))
            ],
          ),
        ),
      ),
    );
  }
}
