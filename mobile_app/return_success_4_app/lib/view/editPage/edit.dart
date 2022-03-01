import 'package:flutter/material.dart';
import 'package:isar/isar.dart';
import 'package:return_success_4_app/controller/notification_service.dart';
import 'package:return_success_4_app/view/editPage/edit_widgets.dart';

import '../../controller/device_database_service.dart';
import '../general_widgets.dart';

/// A page that lets users manage their devices, i.e. subscribe and unsubscribe to devices and topics
class EditPage extends StatelessWidget {
  const EditPage({required this.isar, Key? key}) : super(key: key);

  final Isar isar;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: transparentAppBar(),
      body: SingleChildScrollView(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.start,
          crossAxisAlignment: CrossAxisAlignment.start,
          children: <Widget>[
            // Form to subscribe to new devices
            SubscriptionForm(isar: isar),
            const Padding(
              padding: EdgeInsets.fromLTRB(16, 24, 8, 16),
              child: Text(
                "My devices:",
                style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold),
              ),
            ),
            // List of all devices that the app is subscribed to
            SubscribedList(isar: isar),
          ],
        ),
      ),
    );
  }
}

/// A card containing a Form allowing the user to subscribe
/// to the notifications of new devices
class SubscriptionForm extends StatefulWidget {
  const SubscriptionForm({required this.isar, Key? key}) : super(key: key);

  final Isar isar;

  @override
  State<SubscriptionForm> createState() => _SubscriptionFormState();
}

class _SubscriptionFormState extends State<SubscriptionForm> {
  late TextEditingController textController1;
  late TextEditingController textController2;

  final _formKey = GlobalKey<FormState>();

  String? selectedValue;

  @override
  void initState() {
    super.initState();
    textController1 = TextEditingController();
    textController2 = TextEditingController();
  }

  String? formValidator(String? value) {
    if (value == null || value.isEmpty) {
      return 'Please enter some text';
    }
    if (RegExp(r'^[a-zA-Z0-9-_.~%]{1,900}$').hasMatch(value)) {
      return null;
    }
    return 'Not a valid input';
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.all(12.0),
      padding: const EdgeInsets.fromLTRB(16.0, 8.0, 16.0, 16.0),
      decoration: const BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.all(Radius.circular(20)),
        boxShadow: [
          BoxShadow(
            color: Color.fromARGB(50, 0, 0, 0),
            offset: Offset(2, 2),
            blurRadius: 8,
          ),
        ],
      ),
      child: Form(
        key: _formKey,
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            // DeviceID Text Field
            TextFormField(
              validator: formValidator,
              controller: textController1,
              decoration: const InputDecoration(
                border: InputBorder.none,
                label: Text(
                  "Device ID:",
                  style: TextStyle(
                      fontWeight: FontWeight.w500, color: Colors.black),
                ),
              ),
            ),
            // Topic DropDown Menu
            Row(
              children: [
                const Text(
                  "Detection mode:  ",
                  style: TextStyle(
                    fontSize: 16,
                    fontWeight: FontWeight.w500,
                  ),
                ),
                DropdownButton(
                    value: selectedValue,
                    hint: const Text("Choose one    "),
                    items: const [
                      DropdownMenuItem(
                        child: Text("Doorbell"),
                        value: "doorbell",
                      ),
                      DropdownMenuItem(
                        child: Text("Fire Alarm"),
                        value: "fire_alarm",
                      ),
                    ],
                    onChanged: (String? value) {
                      setState(() {
                        selectedValue = value;
                      });
                    }),
              ],
            ),
            const SizedBox(
              height: 20,
            ),
            // Add to devices button
            iconButton(
              size: 30,
              label: "Add new device and/or mode",
              labelWeight: FontWeight.bold,
              icon: Icons.add_rounded,
              iconRatio: 4.0 / 5.0,
              color: const Color.fromARGB(255, 5, 107, 190),
              onPressed: () {
                if (_formKey.currentState!.validate()) {
                  if (selectedValue != null) {
                    DeviceDatabaseService().addTopicToDevicesDB(
                        widget.isar, textController1.text, selectedValue!);
                    final newTopic =
                        textController1.text + "_" + selectedValue!;
                    NotificationService().subscribeToTopics([newTopic]);
                  }
                }
              },
            ),
          ],
        ),
      ),
    );
  }
}
