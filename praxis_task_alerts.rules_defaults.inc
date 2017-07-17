<?php
/**
 * @file
 * praxis_task_alerts.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function praxis_task_alerts_default_rules_configuration() {
  $items = array();
  $items['rules_failed_task_alerts'] = entity_import('rules_config', '{ "rules_failed_task_alerts" : {
      "LABEL" : "Failed task alerts",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "aegir_rules", "rules" ],
      "ON" : { "post_hosting_default_execute" : [] },
      "IF" : [
        { "aegir_rules_condition_task_status_failure" : { "task" : [ "task" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[site:mail]",
            "subject" : "[monitoring] \\u00c9chec de \\u0022[task:task-type]\\u0022 sur [task:title] (serveur: [site:url])",
            "message" : "\\u00c9chec de: [task:title]\\r\\n\\r\\nVoir la t\\u00e2che: [task:url]\\r\\n\\r\\nCeci est un message automatis\\u00e9.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
