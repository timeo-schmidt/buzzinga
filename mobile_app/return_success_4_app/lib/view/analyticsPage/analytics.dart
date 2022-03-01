import 'package:flutter/material.dart';
import 'package:isar/isar.dart';

import '../general_widgets.dart';
import 'bar_char.dart';
import 'confusion_matrix.dart';

/// A page that displays detailed information about the usage of the app,
/// as well as the confusion matrix of the NN model used by the devices.
class AnalyticsPage extends StatefulWidget {
  const AnalyticsPage({required this.isar, Key? key}) : super(key: key);

  final Isar isar;

  @override
  State<AnalyticsPage> createState() => _AnalyticsPageState();
}

class _AnalyticsPageState extends State<AnalyticsPage> {
  //Boolean to display dummy data in the charts
  late bool demoMode;

  @override
  void initState() {
    demoMode = false;
    super.initState();
  }

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
              // // Title
              // const Padding(
              //   padding: EdgeInsets.only(left: 8.0, bottom: 4.0),
              //   child: Text(
              //     "Confusion matrix:",
              //     style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
              //   ),
              // ),
              // // Confusion matrix card of the NN model
              // confusionMatrixCard(),
              // const SizedBox(
              //   height: 48,
              // ),
              // Title
              const Padding(
                padding: EdgeInsets.only(left: 8.0, bottom: 4.0),
                child: Text(
                  "Analytics:",
                  style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
                ),
              ),
              // Bar chart for 'Doorbell' messages analytics
              AnalyticsBarChart(
                label: "Doorbell alerts in the past months:",
                category: "Doorbell",
                isar: widget.isar,
                colorProfile: const [
                  Colors.lightBlueAccent,
                  Colors.greenAccent
                ],
                demoMode: demoMode,
              ),
              // Bar chart for 'Fire Alarm' messages analytics
              AnalyticsBarChart(
                label: "Fire Alarm alerts in the past months:",
                category: "Fire Alarm",
                isar: widget.isar,
                colorProfile: const [
                  Colors.deepOrangeAccent,
                  Colors.orangeAccent
                ],
                demoMode: demoMode,
              ),
              // Demo mode toggle
              Padding(
                padding: const EdgeInsets.all(24),
                child: Row(
                  children: [
                    const Text(
                      "Demo mode:",
                      style: TextStyle(
                        color: Colors.blueGrey,
                        fontSize: 15,
                        fontWeight: FontWeight.w500,
                      ),
                    ),
                    Checkbox(
                        activeColor: Colors.blueGrey,
                        value: demoMode,
                        onChanged: (bool? newValue) {
                          setState(() {
                            demoMode = newValue!;
                          });
                        }),
                  ],
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
